#!/bin/sh
#  ---------------------------------------
# | disable or enable internet connection |
# | S. CELLES                             |
#  ---------------------------------------


room=$2
time=$3


case "$1" in

   start)
      for ip in `cat internet_rules_$room.dat`
      do
         echo "start $ip"
      done
      ;;

    stop)
       for ip in `cat internet_rules_$room.dat`
       do
          echo "stop $ip"
       done
       ;;

    restart)
       $0 stop $2 $3
       sleep 1
       $0 start $2 $3
       ;;

    *)
       echo "Usage: $0 start|stop|restart [room] [time]" >&2
       exit 1
       ;;

esac


exit 0