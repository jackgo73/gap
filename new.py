#!/usr/bin/python3

import sys
import re
from optparse import OptionParser

__version__ = '1.0.0'


def main(args):
    parser = OptionParser(description=__doc__)
    parser.add_option("-n", "--number", help="problems number")
    parser.add_option("-t", "--title", help="problems title")
    parser.add_option("-v", "--version", action="store_true", default=False, help="get version")
    options = parser.parse_args(args)[0]

    if options.version:
        print(__version__)
        return 0

    if not (options.title or options.number):
        parser.error('number/title not given')

    generate_problems(options.number, options.title)

def generate_problems(number: str, title: str):
    number = number.zfill(5)
    title = re.sub(r'(?<!^)(?=[A-Z])', '_', title).lower()

    # src
    src_file_name_cpp = title + ".cpp"
    src_file_name_h = title + ".h"
    src_dir_name = "p_" + number + "_" + title

    # tst
    tst_file_name_cpp = title + "_tst.cpp"
    tst_dir_name = src_dir_name

    print(src_file_name_cpp)
    print(src_file_name_h)
    print(src_dir_name)


if __name__ == '__main__':
    sys.exit(main(sys.argv))