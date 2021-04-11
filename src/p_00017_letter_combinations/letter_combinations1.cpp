#include "letter_combinations.h"

#include "math.h"
#include "string.h"
#include "stdlib.h"

static char  *g_keys[10]={NULL,NULL,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
static int   g_keySize[10] = {1,1,3,3,3,3,3,4,3,4};
static int	  g_cnt = 0;
/**
 * digits: 输入待转换数字(输入参数)
 * depth:  最大路径深度
 * index:  当前深度(0表示根)
 * ans:    返回结果
 * pathWay:记录当前线路的路径编号，与深度同尺寸，存储某一层当前对应第几个元素
 */
void DFS(char *digits, int depth, int index, char **ans, int *pathWay)
{
    // 判断当前解空间是否是符合条件的解, 一条路径
    if(index == depth)
    {
        // 构建 第 g_cnt 个解
        for(int i=0; i<depth; i++)
        {
            char curNum = digits[i];
            char curCharIdx = pathWay[i];
            ans[g_cnt][i] = g_keys[curNum - '0'][curCharIdx];
        }
        g_cnt++;
    }
    else
    {
        int curNum = digits[index] - '0';
        char *curKeyStr = g_keys[curNum];
        int curKeySize = g_keySize[curNum];
        // 指向当前线路第 index 层的元素编号
        int *ptr_pathWayIdx = &pathWay[index];
        *ptr_pathWayIdx = 0;
        for(int i = 0; i<curKeySize; i++)
        {
            // 竖向进入下一层
            DFS(digits, depth, index + 1, ans, pathWay);
            // 横向进入下一个
            (*ptr_pathWayIdx)++;
        }
    }
}

char ** letterCombinations_DFS(char * digits, int* returnSize)
{
    int depth = strlen(digits);	// 最大深度
    if(!digits || !depth)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 1;
    // 组合个数
    for(int i=0; i<depth; i++)
        *returnSize *= g_keySize[digits[i] - 48];

    // 存储组合的空间定义
    char **ret = (char **) malloc(sizeof(char *) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)
        ret[i] = (char *)calloc(depth+1,sizeof(char));
    int pathWay[depth];
    DFS(digits, depth, 0, ret, pathWay);
    return ret;
}
