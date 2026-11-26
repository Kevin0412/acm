# 2025-07-26 · VP 2025 福建师范大学程序设计竞赛

[比赛题目列表](https://codeforces.com/gym/105902) · [完整原题](https://codeforces.com/gym/105902/problems?locale=en)。以下为独立中文摘要。正式比赛日期与本目录练习日期不同。

## A. One Must Imagine Time Tight,
[原题](https://codeforces.com/gym/105902/problem/A) · [a.cpp](a.cpp)

三名队员赶赴赛场，三种交通方案耗时 a,b,c，输出最短耗时。输入三个 1..60 的整数。
代码：两次 min。

## C. Sequential Sequence
[原题](https://codeforces.com/gym/105902/problem/C) · [c.cpp](c.cpp)

支持单点赋值及询问子数组排序后是否由互异连续整数构成。输入 T 组 n,q、数组；1 x y 修改，2 l r 询问，输出 YES/NO。n,q≤10^5，总 n、总 q 各≤2×10^5。
代码：维护区间最值以及每个位置的下一个同值位置，判定 max-min=r-l 且最小后继>r。以 set 维护同值下标，修改时更新相邻后继。模板来源待核。

## D. Where's My Money?
[原题](https://codeforces.com/gym/105902/problem/D) · [d.cpp](d.cpp) · [d.py](d.py)

三名队员比赛出行时轮流垫付，给三份账单，构造六个有向转账金额，使最终各自承担费用的差不超过 0.01。输入多组 n,m,p 及三组金额；输出顺序 AB、AC、BA、BC、CA、CB，金额非负，无须最少转账。
C++ 按高于或低于平均值的组合分情况分配，再修正分币舍入；Python 按差额比例分配。浮点舍入与全部相等情况需检验。

## E. Binary Banter: Counting Combinatorial Bits
[原题](https://codeforces.com/gym/105902/problem/E) · [e.cpp](e.cpp)

计算 S(n)=Σ(i=0..n)Σ(j=0..i)[C(i,j) mod 2]，结果模 998244353。T≤3×10^5，n≤10^18。
代码：令 N=n+1，从高到低扫描 N 的置位。每遇第 i 位的 1，贡献 3^i × 2^k，其中 k 为此前遇到的 1 数。预计算 2、3 的幂，单组 O(log n)。
数学解释：Lucas 定理给出第 i 行有 2^popcount(i) 个奇数；完整 2^k 行块贡献 3^k。原代码没有直接计算组合数。
自拟例：n=7，答案 27。

## F. Imbalanced Bracket
[原题](https://codeforces.com/gym/105902/problem/F) · [f.cpp](f.cpp)

给括号串，每次翻转一个字符，最少翻转多少次才能令每个非空子序列均不合法（不存在合法非空括号子序列）？多组 n 和字符串，总 n≤2×10^5。
代码：目标串必须为若干右括号后接若干左括号，否则存在 () 子序列；枚举分界点，用左括号前缀计数算最小翻转次数。O(n)。

## K1. MST(a.k.a. Most Shortened Terms)
[原题](https://codeforces.com/gym/105902/problem/K1) · [k1.cpp](k1.cpp)

每组给三个单词的长度及单词，判断首字母是否依次为 M、S、T。输出 YES/NO。
代码：只比较首字符。

## L. We Luv Stamina
[原题](https://codeforces.com/gym/105902/problem/L) · [l.cpp](l.cpp)

四键音游谱面为 n×4 的 01 矩阵，保证同列相邻行不同时为 1。自下向上扫描，相邻两行若要求同一只手（左手对应前两列，右手后两列）连续击键，就将上行该手的音符移到下行同列。输出变换后的谱面。n≤1000。
代码：直接按题意模拟，每只手分别处理两个交叉列的情况。O(n)。

## G. Still No Money?
[原题](https://codeforces.com/gym/105902/problem/G) · [g.cpp](g.cpp)
两人轮流取烤串，每次最多取当前 k 根、取完后 k 减 1；不能行动者输，求最优策略胜者。文件 solve 为空，仅作题号索引。

本目录有效实现与草稿不代表提交结果。