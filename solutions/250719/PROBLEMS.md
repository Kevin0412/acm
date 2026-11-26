# 250719 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [2025 四川省赛 Gym 105949J Sichuan Provincial Contest](https://codeforces.com/gym/105949/problem/J)

原始代码：[j.cpp](j.cpp)、[j.py](j.py)、[j1.cpp](j1.cpp)

数树上恰好五点组成 SCCPC 的简单路径。j.cpp 以正反前缀长度状态进行树形 DP，按不同子树乘积统计穿过节点的路径；j.py 以第二个 C 为中心，计数左侧 S-C-C 和右侧 C-P-C；j1.cpp 为通用 KMP 路径搜索，输入协议也不匹配原题。三个版本来源/正确性/时间顺序未核。

[整理来源](../../docs/problem-archive-02.md)