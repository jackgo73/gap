




## 动态规划
```c
# 不过是一个 N 叉树的遍历问题而已
def dp(n):
    for coin in coins:
        dp(n - coin)
```

p_00322_coin_change       凑零钱
p_00509_fib               汉诺塔



## 树

模版
```c
void traverse(TreeNode root) {
    // 前序遍历
    traverse(root.left)
    // 中序遍历
    traverse(root.right)
    // 后序遍历
}
```
p_00105_build_tree        给前序中序构造树（递归一定要传地址）
p_00124_max_path_sum      路径最大和


## 前缀和数组（连续求和问题）
https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/qi-ta-suan-fa-ji-qiao/qian-zhui-he-ji-qiao

p_00560_subarray_sum      连续和等于k的次数

## 未归类



p_00046_permute
