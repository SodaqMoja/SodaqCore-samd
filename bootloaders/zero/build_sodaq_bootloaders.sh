#!/bin/bash -ex

# Set DEBUG env to enable debug version
# DEBUG=DEBUG=1 ./build_sodaq_bootloaders.sh

make ${DEBUG} BOARD_ID=sodaq_explorer SAM0_VARIANT=SAMD21J18A NAME=samd21_sam_ba_explorer clean all
mkdir -p ../explorer
mv -v samd21_sam_ba_explorer.* ../explorer/

make ${DEBUG} BOARD_ID=sodaq_one SAM0_VARIANT=SAMD21G18A NAME=samd21_sam_ba_one clean all
mkdir -p ../one
mv -v samd21_sam_ba_one.* ../one/

make ${DEBUG} BOARD_ID=sodaq_one SAM0_VARIANT=SAMD21G18A NAME=samd21_sam_ba_one_no_dt DISABLE_DOUBLE_TAP=1 clean all
mkdir -p ../one_no_dt
mv -v samd21_sam_ba_one_no_dt.* ../one_no_dt/

make ${DEBUG} BOARD_ID=sodaq_autonomo SAM0_VARIANT=SAMD21J18A NAME=samd21_sam_ba_autonomo clean all
mkdir -p ../autonomo
mv -v samd21_sam_ba_autonomo.* ../autonomo/

make ${DEBUG} BOARD_ID=sodaq_sff SAM0_VARIANT=SAMD21G18A NAME=samd21_sam_ba_sff clean all
mkdir -p ../sff
mv -v samd21_sam_ba_sff.* ../sff/

echo Done building bootloaders!
