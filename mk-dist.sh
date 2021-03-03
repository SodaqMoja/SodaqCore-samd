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
MYTMPDIR=$(mktemp -d ./distXXXXXXXXXX)
TOPLEVEL=SodaqCore-samd-${VERSION}

doit()
{
    VER=${1?}
    PREFIX=${2?}
    OLDPWD=${3?}
    TARFILE=${PREFIX}-${VER}.tar.bz2
    tar -cjf ${TARFILE} ${TOPLEVEL}

    python3 ${OLDPWD}/create-package-json.py ${OLDPWD}/package_templates/package_sodaq_samd_index.json ${TARFILE} > package_sodaq_samd_index.json
    python3 ${OLDPWD}/create-package-json.py ${OLDPWD}/package_templates/package_test_sodaq_samd_index.json ${TARFILE} > package_test_sodaq_samd_index.json
    cp -pf ${TARFILE} ${OLDPWD}/
    cp -pf package_sodaq_samd_index.json ${OLDPWD}
    cp -pf package_test_sodaq_samd_index.json ${OLDPWD}
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

mkdir -p $MYTMPDIR/$VERSION
rsync -ai --exclude '*~' --exclude 'build/' --exclude '*.ltrans.*' $DISTFILES $MYTMPDIR/$TOPLEVEL/
# For some reason the files and dirs are made writable for other when running in gitlab-ci
chmod -R o-w $MYTMPDIR/$TOPLEVEL/
OLDPWD=$PWD

(
cd $MYTMPDIR
doit $VERSION $MYNAME $OLDPWD
)

rm -fr $MYTMPDIR
