# 2025-05-11 · Codeforces Round 1024 (Div. 2) 与专题练习
[比赛](https://codeforces.com/contest/2102)。以下是独立中文摘要；原题完整限制、样例见链接。

## A. Dinner Time
[原题](https://codeforces.com/contest/2102/problem/A) · [a.cpp](a.cpp)

给定 n,m,p,q，能否构造一个长度 n 的整数数组，使总和为 m，每个长度 p 的连续段和均为 q？数组允许负数。输入多组 n,m,p,q，输出 YES/NO。
代码：相邻长度 p 的段和相等推出周期 p；若 n 是 p 的倍数，必须满足 n*q=m*p，否则剩余段可以调节总和。
自拟例：n=4,m=6,p=2,q=3，答案 YES。

## B. The Picky Cat
[原题](https://codeforces.com/contest/2102/problem/B) · [b.cpp](b.cpp)

给定绝对值两两不同的数组，任意元素可取反，问能否使第一个元素成为整个数组的中位数（排序后第 ceil(n/2) 项）。输入多组 n 与数组，输出 YES/NO。
代码只统计绝对值严格小于首元素的数量，与 n/2 比较。

## C. Mex in the Grid
[原题](https://codeforces.com/contest/2102/problem/C) · [c.cpp](c.cpp)

将 0..n²-1 各放一次到 n×n 网格，使所有矩形子网格的 MEX 之和最大。输入多组 n，输出任意最优网格。
代码：预先生成 500×500 从中心向外扩张的矩阵，按 n 截取中心方块。利用小数尽可能靠中心，使包含 0..k 的矩形更多。未核实所有奇偶尺寸及 AC 状态。

## 专题：互不侵犯（候选匹配）
[洛谷 P1896](https://www.luogu.com.cn/problem/P1896) · [未命名-3.cpp](未命名-3.cpp)

在 n×n 棋盘上放 k 个国王，任意两王不能在水平、垂直或对角相邻格，求放法数。输入 n,k，输出整数方案数。
代码枚举合法行掩码、预计算相邻行兼容关系、滚动 DP。题面吻合但来源/原创性未验证。