# 2026-04-27 · VP 第三届 Universal Cup Stage 8: Cangqian

[官方题册](https://assets.ucup.ac/statements/statements-3-8.pdf)（2024-08-31 至 09-01，第 2、10 页）。两题均已由正式题册核对。

## A. Bingo
[题册第 2 页](https://assets.ucup.ac/statements/statements-3-8.pdf#page=2) · [a.cpp](a.cpp)

给正整数 n,m，寻找最小的严格大于 n 的整数 x，使 x 是 m 的倍数，或者 x 的十进制表示含有 m 的十进制表示作为连续子串。T≤10^5，n 最多 10^6 位，m≤10^9，总位数规模≤3×10^6。
代码以 10^38 为基数，每块存 signed __int128，求 n 模 m 并得到下一个倍数作为上界；再检查低位的子串替换候选，以 KMP 搜索 n+1 的逆序表示及 m-1 的对应字符串，比较候选大小。该实现有明显风险：pow10 预处理最后一次计算 10^39 超过 signed __int128，最高块进位及候选跨块处理也需检验；未运行或确认 AC。
自拟例：n=20,m=7，答案 21；n=26,m=7，答案 27。
算法观察：下一个倍数必在 n+1..n+m 内，可用该上界限制子串构造的变化范围，而无需遍历百万位大整数之间的所有整数。

## F. Stage: Agausscrab
[QOJ 8937](https://qoj.ac/problem/8937) · [题册第 10 页](https://assets.ucup.ac/statements/statements-3-8.pdf#page=10) · [f.cpp](f.cpp)

给 n 个出题人的名字及各自出题数，名次为严格比自己出题更多的人数加一。每个人去掉名字最后 rank 个字符（不足则整个删除），按原顺序拼接剩余字符串并将首字母大写，输出 Stage: 后接结果。n≤1000，名字长度 2..20，出题数 1..10。
代码按出题数降序计算并列名次，再按原下标排序，截取并拼接。O(n log n)。
自拟例：amy 2、bob 1，输出 Stage: Amb。
