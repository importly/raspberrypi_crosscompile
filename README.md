This is a template cross-compiler for a 64 bit raspberry pi  

deploy with:  

./deploy.sh  

commands for sync: replace ip with your raspberry  

Command 1: rsync -avz --rsync-path="sudo rsync" --delete importly@192.168.1.105:/lib rootfs  
Command 2: rsync -avz --rsync-path="sudo rsync" --delete pi@192.168.1.47:/usr/include rootfs/usr  
Command 3: rsync -avz --rsync-path="sudo rsync" --delete pi@192.168.1.47:/usr/lib rootfs/usr  
Command 4: rsync -avz --rsync-path="sudo rsync" --delete pi@192.168.1.47:/opt/vc rootfs/opt  

currently tested on a raspberry pi 3 b+.  

(note: I wanted to use WiringPi for controlling the GPIO pins but that doesn't work on 64 bit. Instead, I used pigpio.   
When testing, this command is useful because pigpio is a daemon process.   

sudo kill -9 $(cat /var/run/pigpio.pid)  

)  

refrence url: https://github.com/abhiTronix/raspberry-pi-cross-compilers/wiki/Cross-Compiler-CMake-Usage-Guide-with-rsynced-Raspberry-Pi-64-bit-OS#cross-compiler-cmake-usage-guide-with-rsynced-raspberry-pi-64-bit-os 
