# 251114 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [Gym 106184A 秘术「天文密葬法」](https://codeforces.com/gym/106184/problem/A)

原始代码：[25harbinwarmup_a.cpp](25harbinwarmup_a.cpp)

给出可能有数百万位的 n!/m，已知 1≤m<n≤10^6，反求 n,m

代码笔记：对阶乘取 log10 前缀和；用位数和头部数字近似 log10 输入，再二分 n，指数还原 m 并四舍五入。浮点误差和边界待检验。

[整理来源](../../docs/problem-archive-01.md)