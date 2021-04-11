#ifndef P_00046_PERMUTE
#define P_00046_PERMUTE

#include <list>
#include <vector>

using namespace std;

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int> &nums);

    void backtrack(vector<int> &vector, list<int> list);
};




#endif //P_00046_PERMUTE
