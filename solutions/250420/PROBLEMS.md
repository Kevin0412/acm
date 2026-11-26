# 250420 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [洛谷 P1115 最大子段和](https://www.luogu.com.cn/problem/P1115)（高度吻合的候选）

原始代码：[c.cpp](c.cpp)

求非空连续子数组的最大和

代码笔记：max0 表示以当前位置结尾的最大和，max1 维护全局答案；线性 DP。模板题无法仅凭代码唯一识别。

[整理来源](../../docs/problem-archive-01.md)

## 2. [P1314 聪明的质监员](https://www.luogu.com.cn/problem/P1314)

原始代码：[d.cpp](d.cpp)

选重量阈值 W；各区间内合格物品数量乘价值和再累加，令结果尽量接近 S

代码笔记：两套前缀和+阈值二分；末尾手动计算两侧候选，O((n+m)log W)。

[整理来源](../../docs/problem-archive-01.md)

## 3. [P1638 逛画展](https://www.luogu.com.cn/problem/P1638)

原始代码：[e.cpp](e.cpp)

求覆盖全部 m 类的最短连续区间

代码笔记：set 判断首次覆盖，频次数组维护窗口，左端冗余时收缩；保存每个候选区间，再找最短。

[整理来源](../../docs/problem-archive-01.md)

## 4. [P3406 海底高铁](https://www.luogu.com.cn/problem/P3406)

原始代码：[f.cpp](f.cpp)

按访问城市顺序统计经过的铁路段，在单次票与办卡方案中择便宜者

代码笔记：差分累计每段经过次数，最后逐段 min(a*c,b*c+固定费)。检查 d[n-1] 未初始化但可能被读写的问题；不据此判 AC。

[整理来源](../../docs/problem-archive-01.md)