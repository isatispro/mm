#! /bin/bash

cat /proc/`pidof mm`/maps >maps.log
cat /proc/`pidof mm`/smaps >smaps.log
readelf -a mm > mm_elf.log
readelf -a libmm.so > libmm_elf.log


