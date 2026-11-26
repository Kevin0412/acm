# 250722 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [2025 江苏／广东省赛 Gym 105945F Ranking Prediction](https://codeforces.com/gym/105945/problem/F)

原始代码：[f.cpp](f.cpp)、[f1.cpp](f1.cpp)

封榜后根据另一队的未知提交推算至少几次待定提交成为 AC 才能严格超过己方。统计已过题和罚时，对每道未过且有待定提交的题取最早待定时间加之前的已知失败罚时，排序前缀和枚举。

[整理来源](../../docs/problem-archive-02.md)

## 2. [105945H Loose Subsequences](https://codeforces.com/gym/105945/problem/H)

原始代码：[h.cpp](h.cpp)

相邻所选原串下标之差大于 k，统计不同的非空子序列。每个状态只保存每种字符的最早可选位置，形成向右的 DAG；显式栈记忆化计数。事实上可以直接按下标逆序 DP；原代码状态约 112 MB，时间/AC 待核。

[整理来源](../../docs/problem-archive-02.md)