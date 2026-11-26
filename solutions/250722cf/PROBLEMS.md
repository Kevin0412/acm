# Educational Codeforces Round 181 (Div. 2) — CF 2125

[比赛原题](https://codeforces.com/contest/2125)。以下为独立中文题意整理；完整限制、官方样例以原题为准。例子为自拟，非评测结果。

## A. Difficult Contest
[原题](https://codeforces.com/contest/2125/problem/A) | [a.cpp](a.cpp)

给定大写英文字母串，重排所有字符，使串中不存在连续子串 FFT 或 NTT。每组输入一个字符串，输出任意合法重排。例：FFT → TFF。
代码：把 T 全部放在开头，其余按字母计数输出。

## B. Left and Down
[原题](https://codeforces.com/contest/2125/problem/B) | [b.cpp](b.cpp)

机器人位于 (a,b)，每步选 0≤dx,dy≤k，向左 dx、向下 dy。首次使用某个有序数对花费 1，重复使用同一数对免费。求到原点的最低总费用。每组输入 a,b,k（均不超过 10^18），输出最小费用。
例：a=6,b=9,k=3，重复 (2,3) 三次，费用 1。
代码：gcd 约分后检查两分量是否均 ≤k。

## C. Count Good Numbers
[原题](https://codeforces.com/contest/2125/problem/C) | [c.cpp](c.cpp)

若正整数的全部质因子均至少为两位数，则称其为好数；1 不计入。每组给定闭区间 [l,r]，求好数数量。例：[10,20] 内有 11,13,17,19，答案 4。
代码：排除 2,3,5,7 的倍数，利用 210 周期前缀计数；区间询问 O(1)。

## D. Segments Covering
[原题](https://codeforces.com/contest/2125/problem/D) | [d.py](d.py)

长度 m 的格带上有 n 个区间，每个区间 (l,r) 独立以 p/q 的概率存在。求所有格子恰好被一个存在的区间覆盖的概率，按模 998244353 输出。
输入 n,m，接着 n 行 l,r,p,q。例：m=2，只有覆盖 [1,2] 且概率 1/2 的区间，答案为 499122177。
代码：提取全部区间不出现的概率乘积，将选中区间的权重变为 p/(q-p)，再对恰好铺满前缀做 DP；来源待核。

## 跨目录备份：k-MEX
[1007.cpp](1007.cpp) 与 [250801/1007.cpp](../250801/1007.cpp) 内容一致，已匹配 2025 杭电多校第 5 场 1007（[HDU 8033](https://vjudge.net/problem/HDU-8033)）。详见 [250801 题目档案](../250801/PROBLEMS.md)，并非本场 CF 题目。