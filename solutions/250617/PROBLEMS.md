# 250617 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [CF 2121C Those Who Are With Us](https://codeforces.com/contest/2121/problem/C)

原始代码：[c.cpp](c.cpp)

一次选定行列，对其并集的格子各减一，使最大值最小。仅保留最大值的坐标；取首个最大值，分别固定它所在行或列，检查其他最大值能否共用另一列或行。

[整理来源](../../docs/problem-archive-02.md)

## 2. [CF 2121D 1709](https://codeforces.com/contest/2121/problem/D)

原始代码：[d.cpp](d.cpp)

用有限次数的同排相邻交换、同列上下交换，使两排各递增且每列上小下大。代码依次把 1..n 移入上排目标位置，再把 n+1..2n 移入下排；同时记录实际交换和调试输出。

[整理来源](../../docs/problem-archive-02.md)