# 2025 杭电暑期多校第 10 场
[系列题号索引](https://vjudge.net/article/11295)。以下为中文题意摘要，完整限制与样例见题面。

## 1010. Cut Check Bit
[HDU 8096](https://vjudge.net/problem/HDU-8096) · [题面镜像](https://icpc.bjtu.edu.cn/problem/9580) · [1010.cpp](1010.cpp) · [1010_1.cpp](1010_1.cpp)
给非负整数序列 a 及上限 x，将序列切成若干非空连续段。每段计算按位 AND，再将这些结果按位 OR；要求最终值不超过 x，求最大段数，无法满足则 -1。
输入多组，每组 n,m，接着 x 和 n 个数，均以长度 m 的 32 进制字符串输入（0..9、a..v），n*m≤4×10^6，各组乘积之和≤2×10^7。
原代码将每 12 个 32 进制字符压入 60 bit 的 unsigned long long，使用 vector 表示任意长位串，1010.cpp 尝试线段树求区间 AND，1010_1.cpp 尝试 ST 表。两种版本内存开销与正确性均待核；来源未确认。
自拟例：n=2,m=1,x=0,a=[1,2]，两段 OR 为 3，合为一段 AND 为 0，答案 1。

## 1013. Spring River Flower Moon Night
[HDU 8099](https://vjudge.net/problem/HDU-8099) · [题面镜像](https://icpc.bjtu.edu.cn/problem/9583) · [1013.cpp](1013.cpp)
从 (0,0) 走到 (n,m)，向右移动一格代价为当前 y，向上移动一格代价为当前 x。求最小代价。输入 q 组 n,m（0..10^9），每组输出整数。
代码直接输出 n*m，因为每一步代价恰等于势函数 F(x,y)=xy 的增量，所有路径的代价均为 nm。
自拟例：(2,3) 的任意合法单调路径总代价 6。