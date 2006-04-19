#!/bin/sh
#  ---------------------------------------
# | disable or enable internet connection |
# | S. CELLES                             |
#  ---------------------------------------


room=$2
if [ "$room" = "" ]; then room="s32"; fi


time=$3
if [ "$time" = "" ]; then time="60"; fi


case "$1" in

   start)
      for ip in `cat internet_rules_$room.dat`
      do
         echo "start internet connection for $ip for $time minutes"
      done
      ;;

    stop)
       for ip in `cat internet_rules_$room.dat`
       do
          echo "stop internet connection for $ip"
       done
       ;;

    restart)
       $0 stop $room $time
       sleep 1
       $0 start $room $time
       ;;

    *)
       echo "Usage: $0 start|stop|restart [room] [time]" >&2
       exit 1
       ;;

esac


exit 0