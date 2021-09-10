#!/bin/bash

if [[ $# != 2 ]] ; then
echo "USAGE: $0 number title "
echo " e.g.: $0 4 findMedianSortedArrays"
exit 1;
fi

number=$(printf "%05d\n" ${1})
title=$(echo "${2}" | sed -E 's/([A-Z])/_\1/g' | sed -E 's/^_//g' | tr 'A-Z' 'a-z')
utitle=$(echo "${title}" | tr "[a-z]" "[A-Z]")


src_name="p_${number}_$title.c"
tst_name="ut_${number}_$title.cpp"

echo "src file name: " ${src_name}
echo "tst file name: " ${tst_name}

touch src/${src_name}
cat << EOF > src/${src_name}

EOF

touch tst/${tst_name}
cat << EOF > tst/"${tst_name}"
#include "gtest/gtest.h"
#include "${src_name}"

TEST(${utitle}, TEST01) {
	EXPECT_EQ (1, 1);
}
EOF
