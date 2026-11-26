# 250719cf 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [CF 2122C Manhattan Pairs](https://codeforces.com/contest/2122/problem/C)

原始代码：[c.cpp](c.cpp)、[c1.cpp](c1.cpp)

偶数个平面点两两配对，使曼哈顿距离和最大

代码笔记：c 按 x+y、x-y 两套排序，尝试反复选当前最远点对；有末轮指针越界风险，局部最远不保证全局最优。c1 枚举多种排序配法，不保证最优。

[整理来源](../../docs/problem-archive-01.md)