#!/bin/sh
#
# This script creates a new distribution for the SODAQ SAMD boards
# The tar.bz2 is created and the two lines for the JSON are printed
#
# Unfortunately the checksum will be different each time this script
# is run. The toplevel directory gets a new date-time stamp and thus
# the checksum of the tar is different.

MYNAME=sodaqsamdboards
DISTFILES='boards.txt bootloaders cores libraries platform.txt programmers.txt variants'

VERSION=$(sed -n 's/version=//p' platform.txt)
TOPLEVEL=$(basename $PWD)

doit()
{
    TARNAME=${1?}
    TOPLEVEL=${2?}
    TARFILE=${TARNAME}.tar.bz2
    tar -cjf ${TARFILE} ${TOPLEVEL}
    CRC=$(sha256sum ${TARFILE}  | awk '{print $1}')
    echo
    echo "TARFILE = '${TARFILE}'"
    echo "\"checksum\":\"SHA-256:${CRC}\"",
    echo "\"size\":\"$(cat ${TARFILE} | wc -c)\"",
    cp -p $TARFILE $OLDPWD/
}

check_presence()
{
    for f in $@
    do
        [ ! -f "$f" -a ! -d "$f" ] && { echo "ERROR: Missing '$f'" ; exit 1; }
    done
}

check_version()
{
    CORE_VERSION=$(sed -r -n 's/.*CORE_VERSION "[^ ]+ v?(.+)"/\1/p' cores/arduino/Arduino.h)
    [ $CORE_VERSION != $VERSION ] && { echo "ERROR: platform.txt version $VERSION does not match CORE_VERSION $CORE_VERSION"; exit 1; }
}

check_presence $DISTFILES

check_version

MYTMPDIR=$(mktemp -d ./distXXXXXXXXXX)
mkdir -p $MYTMPDIR/$TOPLEVEL-$VERSION
rsync -ai --exclude '*~' --exclude 'build/' $DISTFILES $MYTMPDIR/$TOPLEVEL-$VERSION/
OLDPWD=$PWD

(
cd $MYTMPDIR
doit $MYNAME-$VERSION $TOPLEVEL-$VERSION
)

rm -fr $MYTMPDIR
