# 251009 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [P3865 ST 表与 RMQ](https://www.luogu.com.cn/problem/P3865)

原始代码：[P3865_1.cpp](P3865_1.cpp)、[P3865_2.cpp](P3865_2.cpp)

静态数组多次区间最大值询问，题目要求 O(1) 查询

代码笔记：_1 使用带 lazy 的线段树，查询 O(log n)；_2 稀疏表预处理 O(n log n)，查询 O(1)。文件中线段树注释残留区间和字样。

[整理来源](../../docs/problem-archive-01.md)

## 2. [P1908 逆序对](https://www.luogu.com.cn/problem/P1908)

原始代码：[p1908_1.cpp](p1908_1.cpp)、[p1908_2.cpp](p1908_2.cpp)

统计 i<j 且 a_i>a_j 的数对数量

代码笔记：归并计数 vs 按值降序、同值下标降序后用树状数组计数；均 O(n log n)。模板来源待核。

[整理来源](../../docs/problem-archive-01.md)

## 3. [Gym 105578G Guess the Polygon](https://codeforces.com/gym/105578/problem/G)

原始代码：[24shengyangICPC_G.py](24shengyangICPC_G.py)

顶点次序打乱，至多 n-2 次查询竖直截线长度，求多边形面积的精确分数

代码笔记：按 x 坐标分组，构造查询并外推端点截线长度，以梯形面积累加；文件明确自记 CF WA test4、QOJ RE test4。Python int(p/c) 经过浮点，存在精度风险；查询策略等仍待查。

[整理来源](../../docs/problem-archive-01.md)