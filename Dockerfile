# This is a docker to build an Arduino application of a board from the SODAQ
# series.
#
# Please note that there are two versions:
#  * the Arduino IDE version
#  * the boards version
# The version for this docker uses the boards version, and it is based on a docker
# for the IDE version.

# Build the image with:
#   BOARDS_VERSION=1.8.1
#   docker build --rm -t gitlab.m2m4all.com:5050/arduino/dockers/sodaq-arduino:${BOARDS_VERSION} .
#     If apt-get fails you may want to disable cache: --no-cache
#   docker login gitlab.m2m4all.com:5050
#   docker push gitlab.m2m4all.com:5050/arduino/dockers/sodaq-arduino:${BOARDS_VERSION}

# Here, use Arduino IDE version !!!
FROM gitlab.m2m4all.com:5050/arduino/dockers/sodaq-arduino-base:1.8.6

LABEL maintainer="Kees Bakker <kees.bakker@sodaq.com>"

# TODO
# Place the boards tar and json directly in "staging"
# Or,
# Place the boards tar and json on a server somewhere where we can access them.

ARG BOARDS_VERSION

RUN mkdir /board-json
COPY sodaqsamdboards-${BOARDS_VERSION}.tar.bz2 /board-json/
COPY package_sodaq_samd_index.json /board-json/
RUN sed -i 's@http://downloads.sodaq.net/@file:///board-json/@' /board-json/package_sodaq_samd_index.json

ENV JSONURL file:///board-json/package_sodaq_samd_index.json
RUN arduino --pref boardsmanager.additional.urls=${JSONURL} --save-prefs
RUN arduino --install-boards "SODAQ:samd"

CMD ["/bin/bash"]
