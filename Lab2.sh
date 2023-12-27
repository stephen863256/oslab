#!/bin/bash
gcc -static -o get_ps_num get_ps_num.c
gcc -static -o get_ps_info get_ps_info.c

sudo cp get_ps_num ~/oslab/busybox-1.32.1/_install/
sudo cp get_ps_info ~/oslab/busybox-1.32.1/_install/

cd ~/oslab/busybox-1.32.1/_install/
find . -print0 | cpio --null -ov --format=newc | gzip -9 >  ~/oslab/initramfs-busybox-x64.cpio.gz
cd ~/oslab/linux-4.9.263/
make -j $((`nproc`-1))
qemu-system-x86_64 -kernel ~/oslab/linux-4.9.263/arch/x86_64/boot/bzImage -initrd ~/oslab/initramfs-busybox-x64.cpio.gz --append "nokaslr root=/dev/ram init=/init console=ttyS0 " -nographic
