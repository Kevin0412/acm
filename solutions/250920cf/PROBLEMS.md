# Codeforces Global Round 29 — CF 2147

## A. Shortest Increasing Path
[原题](https://codeforces.com/contest/2147/problem/A) | [a.cpp](a.cpp)

从原点出发，第一步沿 x 正方向，第二步沿 y 正方向，此后交替。每步长度为正整数，且严格大于上一步，目标到达 (x,y)。求最少步数，无解输出 -1。
输入 t 组 x,y，范围均为 1..10^9；每组输出答案。
例：(4,2) 可以按长度 1,2,3 行走，答案 3。
代码：x<y 时两步；x-y≥2 且 y≥2 时三步；否则无解。