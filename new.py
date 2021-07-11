#!/usr/bin/python3

__author__ = "mingjiegao"

import sys
import re
import os
from optparse import OptionParser

__version__ = '1.0.0'


def main(args):
    parser = OptionParser(description=__doc__)
    parser.add_option("-n", "--number", help="problems number")
    parser.add_option("-t", "--title", help="problems title")
    parser.add_option("-m", "--mode", default="p", help="p(problems)/c(contest)")
    parser.add_option("-v", "--version", action="store_true", default=False, help="get version")
    options = parser.parse_args(args)[0]

    if options.version:
        print(__version__)
        return 0

    if not (options.title and options.number):
        parser.error('number/title not given')

    if not (options.mode == "p" or options.mode == "c"):
        parser.error('wrong mode')

    generate_problems(options.number, options.title, options.mode)


def generate_problems(number: str, title: str, mode: str):
    number = number.zfill(5)
    title = re.sub(r'(?<!^)(?=[A-Z])', '_', title).lower()

    # src
    src_file_name_cpp = title + ".cpp"
    src_file_name_h = title + ".h"
    src_dir_name = mode + "_" + number + "_" + title

    src_content_cpp = "#include\"%s\"" % src_file_name_h
    src_content_h = "#ifndef %s\n" % src_dir_name.upper()
    src_content_h += "#define %s\n" % src_dir_name.upper()
    src_content_h += "#include <stdlib.h>\n"
    src_content_h += "#include <stdio.h>\n\n\n\n\n"
    src_content_h += "#endif //%s" % src_dir_name.upper()

    # touch src files
    src_dir_path = "src/%s" % src_dir_name
    folder = os.path.exists(src_dir_path)
    if not folder:
        os.makedirs(src_dir_path)
        f = open(os.path.join(src_dir_path, src_file_name_h), 'w')
        f.write(src_content_h)
        f.close()
        f = open(os.path.join(src_dir_path, src_file_name_cpp), 'w')
        f.write(src_content_cpp)
        f.close()
        print("folder [created]: %s" % src_dir_path)
    else:
        print("folder [existed]: %s" % src_dir_path)

    # tst
    tst_file_name_cpp = title + "_tst.cpp"
    tst_dir_name = src_dir_name

    tst_content_cpp = "#include \"gtest/gtest.h\"\n"
    tst_content_cpp += "#include \"%s/%s\"\n\n\n" % (src_dir_name, src_file_name_h)
    tst_content_cpp += "TEST(%s, basetest1) {\n" % src_dir_name
    tst_content_cpp += "    EXPECT_EQ (1, 1);\n"
    tst_content_cpp += "}\n"

    # touch src files
    tst_dir_path = "tst/%s" % tst_dir_name
    folder = os.path.exists(tst_dir_path)
    if not folder:
        os.makedirs(tst_dir_path)
        f = open(os.path.join(tst_dir_path, tst_file_name_cpp), 'w')
        f.write(tst_content_cpp)
        f.close()
        print("folder [created]: %s" % tst_dir_path)
    else:
        print("folder [existed]: %s" % tst_dir_path)


if __name__ == '__main__':
    sys.exit(main(sys.argv))
