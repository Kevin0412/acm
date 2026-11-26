# Codeforces Round 1051 (Div. 2) — CF 2143

[比赛原题](https://codeforces.com/contest/2143)。以下为中文题意摘要，保留原代码。

## A. All Lengths Subtraction
[原题](https://codeforces.com/contest/2143/problem/A) | [a.cpp](a.cpp)

给定长度 n 的排列，依次对 k=1..n 各做一次操作：任选长度恰好 k 的连续区间，将其中每个值减 1。问能否全部归零。
输入多组，n≤100，给排列；输出 YES/NO。
例：[2,3,1] 可以；[3,1,2] 不可以。
代码：从 n 的位置开始，检查 n-1,n-2,...,1 是否总能在当前区间左右紧邻位置加入。

## B. Discounts
[原题](https://codeforces.com/contest/2143/problem/B) | [b.cpp](b.cpp)

n 件物品价格 a_i，k 张券面值 b_j。面值 x 的券选恰好 x 件物品，组内最便宜的一件免费；物品和券均不能重复参加。求最低购买总价。
输入多组，每组 n,k 以及价格和券面值；输出最低总价。
例：价格 [8,5,2]，券 [2]，可免去 5，总价 10。
代码：商品降序、券升序，每个券取当前最贵的若干物品，把组末价格清零。

## C. Max Tree
[原题](https://codeforces.com/contest/2143/problem/C) | [c.cpp](c.cpp)

n 个树节点分配 1..n 的排列值 p。每条边 (u,v)（u<v）有 x,y 两个权值，若 p_u>p_v 贡献 x，否则贡献 y。求最大化总边贡献的任意排列。
输入多组，每组 n 和 n-1 行 u,v,x,y；输出 n 个排列值。
代码：每条边朝能取较大权值的方向定向；树定向无环，拓扑排序后按降序赋值。

## D1. Inversion Graph Coloring (Easy Version)
[原题](https://codeforces.com/contest/2143/problem/D1) | [d1.cpp](d1.cpp) | [d1_1.cpp](d1_1.cpp)

给定数组，统计可以用两种颜色给所选子序列下标染色、使任意逆序对两端颜色不同的子序列数，含空子序列。等价于可拆成两条非降子序列，或不含长度 3 的严格递减子序列。
输入多组，每组 n≤300 以及 n 个 1..n 的数；输出答案模 1e9+7。
例：[3,2,1] 只有完整序列不合法，答案 7。
d1.cpp：尝试分别统计从各位置开始/结束的非降子序列，再组合逆序端点；此分解可能重复计数，且累加时没有持续取模。d1_1.cpp 的具体实现待进一步核验。