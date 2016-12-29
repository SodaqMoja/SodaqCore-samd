#!/bin/bash -ex

make BOARD_ID=sodaq_explorer NAME=samd21_sam_ba_explorer clean all
mkdir -p ../explorer
mv -v samd21_sam_ba_explorer.* ../explorer/

make BOARD_ID=sodaq_one SAM0_VARIANT=SAMD21G18A NAME=samd21_sam_ba_one clean all
mkdir -p ../one
mv -v samd21_sam_ba_one.* ../one/

make BOARD_ID=sodaq_autonomo NAME=samd21_sam_ba clean all

echo Done building bootloaders!
