# 2025-08-22 · CF / AtCoder 混合练习

## B. Equal Hamming Distances
[ARC151 A](https://atcoder.jp/contests/arc151/tasks/arc151_a) · [b.cpp](b.cpp)
给长度 n 的两个 01 串，输出字典序最小的 01 串，使其与两串的海明距离相同；无解输出 -1。1≤n≤2×10^5。
代码：只在两串不同的位置产生距离差，若这些位置总数为奇数则无解；否则先尽量填 0，待一侧的差异配额满后调整后续位。O(n)。
自拟例：S=00,T=11，答案 01。

## C. Promo
[CF 1697B](https://codeforces.com/problemset/problem/1697/B) · [c.cpp](c.cpp)
n 件商品，每次独立询问 x,y，购买至少 x 件时其中最便宜的 y 件免费，求免费商品价格和的最大值。n,q≤2×10^5。
代码：选最贵的 x 件，排序后用前缀和取其中最便宜的 y 件，单次 O(1)。

## D. Max Multiple
[ABC281 D](https://atcoder.jp/contests/abc281/tasks/abc281_d) · [d.cpp](d.cpp)
从 n 个非负整数恰选 k 个不同下标，使总和能被 d 整除，求最大总和，无解输出 -1。n≤100、d≤100。
代码：背包 DP，按选取数量、模 d 余数保存最大和，倒序更新避免重复选取；dp[i] 对应选 i+1 个数。O(n²d)。

## F. Circular Playlist
[ABC281 C](https://atcoder.jp/contests/abc281/tasks/abc281_c) · [f.cpp](f.cpp)
n 首歌按顺序循环播放，给每首时长以及从开始经过的时间 t，输出当前歌曲编号和该歌曲已播放的时间。代码将 t 对总时长取模，再在前缀和中找第一个严格大于余数的位置。O(n)。

## G. Least Elements
[ABC281 E](https://atcoder.jp/contests/abc281/tasks/abc281_e) · [g.cpp](g.cpp)
给长度 N 的数组，对于每个长度 M 的连续窗口输出其中最小 K 项的和。1≤K≤M≤N≤2×10^5。
代码：离散化后构造每个前缀的可持久化权值线段树，查询每个窗口第 K 小值；首窗直接排序求和，滑动时用新旧第 K 小值修正出入元素的贡献。O(N log N)。比标准双 multiset 解法更复杂，代码来源与 AC 未核。

## I. awoo's Favorite Problem
[CF 1697C](https://codeforces.com/problemset/problem/1697/C) · [i.cpp](i.cpp)
两个由 a,b,c 构成的等长字符串，允许在源串中把 ab 变为 ba，或把 bc 变为 cb。求能否变为目标串，输出 YES/NO。
代码：删除 b 后的骨架必须相同；任意前缀内源串 a 的数量不得少于目标串，源串 c 的数量不得多于目标串。对应 a 只能右移、c 只能左移。O(n)。

本目录题目来自不同比赛，不能按本地字母编号认定为一套正式赛。