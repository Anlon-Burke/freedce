#!/bin/sh
#
# 
# (c) Copyright 1991 OPEN SOFTWARE FOUNDATION, INC.
# (c) Copyright 1991 HEWLETT-PACKARD COMPANY
# (c) Copyright 1991 DIGITAL EQUIPMENT CORPORATION
# To anyone who acknowledges that this file is provided "AS IS"
# without any express or implied warranty:
#                 permission to use, copy, modify, and distribute this
# file for any purpose is hereby granted without fee, provided that
# the above copyright notices and this notice appears in all source
# code copies, and that none of the names of Open Software
# Foundation, Inc., Hewlett-Packard Company, or Digital Equipment
# Corporation be used in advertising or publicity pertaining to
# distribution of the software without specific, written prior
# permission.  Neither Open Software Foundation, Inc., Hewlett-
# Packard Company, nor Digital Equipment Corporation makes any
# representations about the suitability of this software for any
# purpose.
# 
#

case $# in
2) ;;
*) echo "Usage: `basename $0` server_host_name_or_address client_program_directory" 1>&2 ; exit 1;;
esac

cd $2

# An IPv4 address is used as is; a host name is resolved to its first
# IPv4 address (getent, or /etc/hosts if getent is not available).
case $1 in
*[!0-9.]*)
        IP=`getent ahostsv4 $1 2>/dev/null | awk '{ print $1; exit }'`
        if [ -z "$IP" ]; then
                IP=`grep -w $1 /etc/hosts | awk '$1 ~ /^[0-9.]+$/ { print $1; exit }'`
        fi
        ;;
*)
        IP=$1
        ;;
esac

# Tests whose number or name is listed in PERF_SKIP (e.g. "3 8" or "15b")
# are skipped.  Each test is limited to PERF_TIMEOUT seconds (default 120)
# if timeout(1) is available.
TIMEOUT=
if command -v timeout > /dev/null 2>&1; then
        TIMEOUT="timeout ${PERF_TIMEOUT:-120}"
fi

FAILED=""
SKIPPED=""

run_test ()
{
        name=$1
        shift
        case " $PERF_SKIP " in
        *" $name "*|*" `echo $name | tr -d a-z` "*)
                echo "client $name: skipped"
                SKIPPED="$SKIPPED $name"
                return
                ;;
        esac
        echo "client $name"
        $TIMEOUT ./client "$@" || FAILED="$FAILED $name"
}

run_test 0a 0 "ncadg_ip_udp:${IP}[2001]" 3 40 y y
run_test 0b 0 "ncadg_ip_udp:${IP}[2001]" 3 40 y n
run_test 0c 0 "ncadg_ip_udp:${IP}[2001]" 3 40 n y
run_test 0d 0 "ncadg_ip_udp:${IP}[2001]" 3 40 n n
run_test 1a 1 "ncadg_ip_udp:${IP}[2001]" 3 40 y y 400
run_test 1b 1 "ncadg_ip_udp:${IP}[2001]" 3 40 y n 400
run_test 1c 1 "ncadg_ip_udp:${IP}[2001]" 3 10 y y 4000
run_test 1d 1 "ncadg_ip_udp:${IP}[2001]" 3 10 y n 4000
run_test 1e 1 "ncadg_ip_udp:${IP}[2001]" 3 2 y y 100000
run_test 1f 1 "ncadg_ip_udp:${IP}[2001]" 3 2 y n 100000
run_test 2a 2 "ncadg_ip_udp:${IP}[2001]" 3 100 y y 400
run_test 2b 2 "ncadg_ip_udp:${IP}[2001]" 3 100 y n 400
run_test 2c 2 "ncadg_ip_udp:${IP}[2001]" 3 10 y y 4000
run_test 2d 2 "ncadg_ip_udp:${IP}[2001]" 3 10 y n 4000
run_test 2e 2 "ncadg_ip_udp:${IP}[2001]" 3 2 y y 100000
run_test 2f 2 "ncadg_ip_udp:${IP}[2001]" 3 2 y n 100000
run_test 3 3 "ncadg_ip_udp"
run_test 4 4 "ncadg_ip_udp:${IP}[2001]" 3 2
run_test 5 5 "ncadg_ip_udp"
run_test 6a 6 "ncadg_ip_udp:${IP}[2001]" 3 100 y y
run_test 6b 6 "ncadg_ip_udp:${IP}[2001]" 3 100 y n
#echo "client 8"
#client 8 "ncadg_ip_udp:${IP}[2001]" y
run_test 7 7 "ncadg_ip_udp:${IP}[2001]"
run_test 9 9 "ncadg_ip_udp:${IP}[2001]"
run_test 10a 10 "ncadg_ip_udp:${IP}[2001]" 4 3 y y 2
run_test 10b 10 "ncadg_ip_udp:${IP}[2001]" 2 3 y n 2
run_test 10c 10 "ncadg_ip_udp:${IP}[2001]" 4 3 y y 2 1
run_test 10d 10 "ncadg_ip_udp:${IP}[2001]" 2 3 y n 2 1
run_test 10e 10 "ncadg_ip_udp:${IP}[2001]" 4 3 y y 2 2
run_test 10f 10 "ncadg_ip_udp:${IP}[2001]" 2 3 y n 2 2
run_test 12a 12 "ncadg_ip_udp:${IP}[2001]" 2 10 y
run_test 12b 12 "ncadg_ip_udp:${IP}[2001]" 2 10 n
run_test 13 13 "ncadg_ip_udp:${IP}[2001]"
run_test 14a 14 "ncadg_ip_udp:${IP}[2001]" 4 n 1
run_test 14b 14 "ncadg_ip_udp:${IP}[2001]" 4 y 1
run_test 15a 15 "ncadg_ip_udp:${IP}[2001]" 2 y 1
run_test 15b 15 "ncadg_ip_udp:${IP}[2001]" 2 n 1
run_test 15c 15 "ncadg_ip_udp:${IP}[2001]" 2 y 1 5
run_test 15d 15 "ncadg_ip_udp:${IP}[2001]" 2 n 1 5

if [ -n "$SKIPPED" ] ; then
	echo "Skipped tests:$SKIPPED"
fi
if [ -n "$FAILED" ] ; then
	echo "The failed tests were"
	echo "$FAILED"
	exit 1
else
	echo "All tests OK"
	exit 0
fi
