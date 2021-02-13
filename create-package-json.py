#!/usr/bin/env python3
#
# Create the boards package JSON

import argparse
import hashlib
import json
import re


class Usage(Exception):
    """This class is used to catch user errors of argparse"""
    def __init__(self, parser, msg):
        self.parser = parser
        self.msg = msg


def main(argv=None):
    parser = None
    try:
        parser = argparse.ArgumentParser(
            description="A Python program to create the boards package JSON")
        parser.add_argument('json', metavar='JSON', type=str,
                            help='the template for the boards package JSON')
        parser.add_argument('tar', metavar='TAR', type=str,
                            help='the distribution TAR file')
        parser.add_argument('-v', '--verbose', action="store_true", help="be verbose")
    except argparse.ArgumentError as msg:
        # The construction of the parser failed
        raise Usage(parser, msg)

    args = parser.parse_args(argv)

    # Get the version from the name of the TAR file
    pat = re.compile(r"sodaq\w+boards - (?P<ver>.*) \.tar\.\w+", re.VERBOSE)
    m = pat.match(args.tar)
    if not m:
        raise Exception("Cannot determine version from '{}'".format(args.tar))
    version = m.group("ver")

    # Compute SHA256 and size of TAR file
    blob = open(args.tar, "rb").read()
    h = hashlib.sha256()
    h.update(blob)
    checksum = h.hexdigest()
    size = len(blob)

    template_json = json.load(open(args.json))
    #print(json.dumps(template_json, indent=4))

    # Usually there is just one package
    package = template_json["packages"][0]
    #print(json.dumps(package, indent=4))
    assert package["name"] == "SODAQ"
    # Find the platform with the specified version
    for p in package["platforms"]:
        if p["name"] == "SODAQ SAMD Boards" and p["version"] == version:
            p["url"] = p["url"].format(args.tar)
            p["archiveFileName"] = p["archiveFileName"].format(args.tar)
            p["size"] = p["size"].format(size)
            p["checksum"] = p["checksum"].format(checksum)
            break

    print(json.dumps(template_json, indent=4))


if __name__ == "__main__":
    try:
        main()
    except Usage as usg:
        # The construction of the argparser failed
        usg.parser.error(usg.msg)
