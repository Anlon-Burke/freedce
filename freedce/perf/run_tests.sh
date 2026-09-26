#!/bin/sh
#
# Run the perf test suite against a local perf server ("make check").
#
# The server listens on the fixed endpoint 2001 for ncacn_ip_tcp and
# ncadg_ip_udp, which perf_tcp.sh and perf_udp.sh expect.
#
# Some tests need the endpoint mapper (rpcd on port 135).  rpcd has to run
# as root, so it is not started here; if it is not running, these tests
# are skipped.  The UDP broadcast test (3) is skipped unless
# PERF_BROADCAST=1 is set.  More tests can be skipped with PERF_SKIP
# (see perf_tcp.sh).

srcdir=${srcdir:-.}

listening ()
{
        # $1: "tcp" or "udp", $2: port
        if command -v ss > /dev/null 2>&1; then
                ss -ln -"`echo $1 | cut -c1`" | grep -q "[:.]$2 "
        else
                netstat -ln 2>/dev/null | grep "^$1" | grep -q "[:.]$2 "
        fi
}

TCP_SKIP=$PERF_SKIP
UDP_SKIP=$PERF_SKIP
if ! listening tcp 135; then
        echo "rpcd is not running: skipping the tests that need the endpoint mapper"
        TCP_SKIP="$TCP_SKIP 8"
fi
if [ "$PERF_BROADCAST" != 1 ]; then
        UDP_SKIP="$UDP_SKIP 3"
fi

echo "Starting server in the background"
./server 1 ep ncacn_ip_tcp 2001 ep ncadg_ip_udp 2001 > server.log 2>&1 &
server_pid=$!
trap 'kill $server_pid 2> /dev/null' 0 1 2 15

i=0
until listening tcp 2001 && listening udp 2001; do
        i=`expr $i + 1`
        if [ $i -gt 50 ] || ! kill -0 $server_pid 2> /dev/null; then
                echo "The perf server did not start:"
                cat server.log
                exit 1
        fi
        sleep 0.2
done

rc=0

echo "TCP Tests"
PERF_SKIP=$TCP_SKIP sh $srcdir/perf_tcp.sh 127.0.0.1 . || rc=1

echo "UDP Tests"
PERF_SKIP=$UDP_SKIP sh $srcdir/perf_udp.sh 127.0.0.1 . || rc=1

if ! kill -0 $server_pid 2> /dev/null; then
        echo "The perf server died during the tests:"
        cat server.log
        rc=1
fi

exit $rc
