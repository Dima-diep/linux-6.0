export ARCH=x86_64
export SUBARCH=x86_64
#make ARCH=x86_64 SUBARCH=x86_64 CROSS_COMPILE=/usr/bin/x86_64-linux-gnu- bzImage -j3
make ARCH=x86_64 SUBARCH=x86_64 CROSS_COMPILE=/usr/bin/x86_64-linux-gnu- modules -j3
