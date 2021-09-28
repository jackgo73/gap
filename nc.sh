#!/bin/bash

if [[ $# != 3 ]] ; then
echo "USAGE: $0 number title type"
echo " e.g.: $0 23 MergeKLists slist"
exit 1;
fi

number=$(printf "%05d\n" ${1})
# title=$(echo "${2}" | sed -E 's/([A-Z])/_\1/g' | sed -E 's/^_//g' | tr 'A-Z' 'a-z')
title=$(echo "${2}")
#utitle=$(echo "${title}" | tr "[a-z]" "[A-Z]")
type=${3}

problem_name="P_${number}_${title}"

hdr_name="${problem_name}.h"
src_name="${problem_name}.cpp"
tst_name="${problem_name}_UT.cpp"

echo "hdr file name: " ${hdr_name}
echo "src file name: " ${src_name}
echo "tst file name: " ${tst_name}
echo "type: " ${type}


touch src/include/${hdr_name}
cat << EOF > src/include/${hdr_name}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <inttypes.h>

EOF

touch src/${type}/${src_name}
cat << EOF > src/${type}/${src_name}
#include "${hdr_name}"

EOF



touch tst/${type}/${tst_name}
cat << EOF > tst/${type}/"${tst_name}"
#include "gtest/gtest.h"
#include "${hdr_name}"

TEST(${problem_name}, TEST01) {

    EXPECT_EQ (1, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
EOF

cat << EOF >> tst/CmakeLists.txt
gap_test("${type}/${tst_name}")
EOF
