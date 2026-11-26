# 250717cf 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [CF 2126C I Will Definitely Make It](https://codeforces.com/contest/2126/problem/C)

原始代码：[c.cpp](c.cpp)、[c1.cpp](c1.cpp)

水位随时间上涨，从一座塔传送到另一座塔耗时为高度差，能否到最高塔

代码笔记：c 排序后逐步跳到下一个更高高度；c1 用 BFS 但错误限制相邻下标并逐时间模拟。两个版本来源/顺序未核实。

[整理来源](../../docs/problem-archive-01.md)

## 2. [CF 2126D This Is the Last Time](https://codeforces.com/contest/2126/problem/D)

原始代码：[d.cpp](d.cpp)、[d2.cpp](d2.cpp)

初始 k，若钱数在赌场允许区间则可变为指定值；每处最多一次，求最大最终值

代码笔记：d 重复扫描可用区间，选择最大 real，可能下降且有 O(n²) 风险；d2 尝试坐标压缩+线段树，不确认正确性与作者归属。标准思路可利用 l≤real≤r 的单调性只做增益。

[整理来源](../../docs/problem-archive-01.md)