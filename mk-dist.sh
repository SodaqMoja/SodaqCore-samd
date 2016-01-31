#!/bin/sh
#
# This script creates a new distribution for the SODAQ SAMD boards
# The tar.bz2 is created and the two lines for the JSON are printed
#
# Unfortunately the checksum will be different each time this script
# is run. The toplevel directory gets a new date-time stamp and thus
# the checksum of the tar is different.

DISTFILES='boards.txt bootloaders cores libraries platform.txt programmers.txt variants'

doit()
{
    VER=${1?}
    PREFIX=${2?}
    TARFILE=${PREFIX}-${VER}.tar.bz2
    tar -cjf ${TARFILE} ${VER}
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

VER=${1?}
MYTMPDIR=$(mktemp -d ./distXXXXXXXXXX)

check_presence $DISTFILES

mkdir -p $MYTMPDIR/$VER
rsync -ai $DISTFILES $MYTMPDIR/$VER/
OLDPWD=$PWD

(
cd $MYTMPDIR
doit $VER sodaqsamdboards $OLDPWD
)

rm -fr $MYTMPDIR
