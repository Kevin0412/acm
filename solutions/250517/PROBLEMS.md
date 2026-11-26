# 250517 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [CF 2109A It's Time To Duel](https://codeforces.com/contest/2109/problem/A)

原始代码：[a.cpp](a.cpp)

线性排列相邻选手各打一场，判断胜场报告是否必然存在谎言。代码尝试以 0/1/2 表示状态传播，而不是直接用相邻两个 0 或全 1 的判定；正确性待核。

[整理来源](../../docs/problem-archive-02.md)

## 2. [CF 2109B Slice to Survive](https://codeforces.com/contest/2109/problem/B)

原始代码：[b.cpp](b.cpp)

切棋盘的玩家与可重新选位置的玩家博弈，求最优步数。枚举首次横切或竖切，后续用向上取整的反复折半计算轮数。

[整理来源](../../docs/problem-archive-02.md)

## 3. [CF 2109C1 Hacking Numbers](https://codeforces.com/contest/2109/problem/C1)

原始代码：[c1.cpp](c1.cpp)、[c1.py](c1.py)

通过不超过 7 条命令把未知正整数变为目标 n；两次数位和后落在 1..9，尝试 add -8,-4,-2,-1 将其归约到 1，再加 n-1。Python 草稿错误调用 flush 参数并覆盖目标变量，不视为可用版本。

[整理来源](../../docs/problem-archive-02.md)