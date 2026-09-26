#!/bin/sh
#
# Short load test against a local lt_server ("make check").
#
# The server listens on a fixed endpoint (LT_ENDPOINT, default 2101) for
# ncacn_ip_tcp and ncadg_ip_udp, so rpcd is not needed.  Steps:
#   1. 8 threads, every operation, 10 s over TCP
#   2. 4 threads, every operation, 5 s over UDP (skipped with LT_UDP=0)
#   3. context rundown: a client exits without closing its 4 contexts;
#      the server has to run them down within 60 s
# The server must still run at the end and must not have found differences.

EP=${LT_ENDPOINT:-2101}
HOST=127.0.0.1

listening ()
{
        # $1: "tcp" or "udp", $2: port
        if command -v ss > /dev/null 2>&1; then
                ss -ln -"`echo $1 | cut -c1`" | grep -q "[:.]$2 "
        else
                netstat -ln 2>/dev/null | grep "^$1" | grep -q "[:.]$2 "
        fi
}

server_value ()
{
        # $1: field of the "server ..." line of lt_client -Q
        ./lt_client -h $HOST -e $EP -Q | sed -n "s/.* $1 \([0-9]*\).*/\1/p"
}

./lt_server -p ncacn_ip_tcp -p ncadg_ip_udp -e $EP > lt_server.log 2>&1 &
server_pid=$!
trap 'kill $server_pid 2> /dev/null' 0 1 2 15

i=0
until listening tcp $EP && listening udp $EP; do
        i=`expr $i + 1`
        if [ $i -gt 50 ] || ! kill -0 $server_pid 2> /dev/null; then
                echo "lt_server did not start:"
                cat lt_server.log
                exit 1
        fi
        sleep 0.2
done

rc=0

echo "TCP: 8 threads, 10 s"
./lt_client -h $HOST -e $EP -t 8 -d 10 || rc=1

if [ "$LT_UDP" != 0 ]; then
        echo "UDP: 4 threads, 5 s"
        ./lt_client -h $HOST -e $EP -P udp -t 4 -d 5 || rc=1
fi

echo "Context rundown"
before=`server_value rundowns`
./lt_client -h $HOST -e $EP -t 4 -n 10 -m ctx_op -k || rc=1
i=0
while :; do
        now=`server_value rundowns`
        if [ -n "$before" ] && [ -n "$now" ] && [ `expr $now - $before` -ge 4 ]; then
                echo "4 contexts run down after about $i s"
                break
        fi
        i=`expr $i + 1`
        if [ $i -gt 60 ]; then
                echo "*** contexts not run down after 60 s (rundowns: $before -> $now)"
                rc=1
                break
        fi
        sleep 1
done

./lt_client -h $HOST -e $EP -Q
if ! kill -0 $server_pid 2> /dev/null; then
        echo "lt_server died:"
        cat lt_server.log
        rc=1
elif [ "`server_value mismatches`" != 0 ]; then
        echo "*** lt_server found differences:"
        cat lt_server.log
        rc=1
fi

exit $rc
