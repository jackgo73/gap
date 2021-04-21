#!/bin/bash

if [[ $# != 2 ]] ; then
echo "USAGE: $0 number title "
echo " e.g.: $0 4 findMedianSortedArrays"
exit 1;
fi

number=$(printf "%05d\n" ${1})
title=$(echo "${2}" | sed -E 's/([A-Z])/_\1/g' | sed -E 's/^_//g' | tr 'A-Z' 'a-z')
utitle=$(echo "${title}" | tr "[a-z]" "[A-Z]")


######################################
#             src dir                #
######################################
dir=p_"$number"_"$title"
file1="$title".cpp
file2="$title".h

mkdir -p src/$dir
touch src/$dir/$file1
touch src/$dir/$file2

cat << EOF > src/$dir/$file1
#include "${file2}"
EOF

cat << EOF > src/$dir/$file2
#ifndef P_${number}_${utitle}
#define P_${number}_${utitle}


class Solution {
};


#endif //P_${number}_${utitle}
EOF

######################################
#            test dir                #
######################################
file3="$title".cpp
mkdir -p tst/$dir
touch tst/$dir/$file3

cat << EOF > tst/$dir/$file3
#include "gtest/gtest.h"
#include "${dir}/${file2}"

TEST(${dir}, basetest1) {
    Solution *s = new Solution();
    // EXPECT_EQ (s->fib(0), 1);
}
EOF
