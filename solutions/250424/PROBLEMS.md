# 250424 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [CF 2106A Dr. TC](https://codeforces.com/contest/2106/problem/A)

原始代码：[a.cpp](a.cpp)

对原二进制串分别翻转一位，统计生成的 n 个串中 1 的总数

代码笔记：不生成矩阵；直接 ones*(n-1)+zeros。O(n)。

[整理来源](../../docs/problem-archive-01.md)

## 2. [CF 2106B St. Chroma](https://codeforces.com/contest/2106/problem/B)

原始代码：[b.cpp](b.cpp)

排列 0..n-1，使前缀 MEX 等于指定 x 的次数最大

代码笔记：先输出小于 x 的数，再倒序输出其余数，让 x 尽量靠后。

[整理来源](../../docs/problem-archive-01.md)

## 3. [CF 2106C Cherry Bomb](https://codeforces.com/contest/2106/problem/C)

原始代码：[c.cpp](c.cpp)

补全 b 的未知项（0..k），要求每个 a_i+b_i 相同，计数

代码笔记：有已知项则共同和被锁定；全未知则数共同和区间 [max(a), k+min(a)] 的整数数目。

[整理来源](../../docs/problem-archive-01.md)

## 4. [CF 2106D Flower Boy](https://codeforces.com/contest/2106/problem/D)

原始代码：[d.cpp](d.cpp)

顺序挑选满足各自最低美丽值的 m 朵花，可至多插入一朵，求其最小必要值或判定无需/不可能

代码笔记：正反两次贪心匹配，尝试拼接前后缀；有 cerr 调试；反向填充写入 c 而非 d、候选未显式取 min 等风险，需测试。

[整理来源](../../docs/problem-archive-01.md)