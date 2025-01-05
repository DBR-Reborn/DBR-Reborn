#!/bin/bash
while :
do
	#this cd makes the debug.log work.
	cd /home/tlny/mud/mudlib
	/usr/bin/driver /home/tlny/mud/mudlib/config.darke > /home/tlny/mud/mudlib/log/driver # -d -fTEST1 -fTEST2
    echo "Press [CTRL+C] to stop.."
	sleep 5s
done
