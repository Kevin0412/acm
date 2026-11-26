# Codeforces Round 1040 (Div. 2) — CF 2130

[比赛原题](https://codeforces.com/contest/2130)。中文摘要，完整限制及官方样例见原题。

## A. Submission is All You Need
[原题](https://codeforces.com/contest/2130/problem/A) | [a.cpp](a.cpp)

给定非负整数多重集，初始分数为 0。反复选取并删除一个子多重集，可以增加其元素和，或者增加其 MEX（最小未出现非负整数）。求最大分数。输入多组，每组 n 及 n 个元素；输出最大分数。
例：{0,0,2}，两个 0 分别按 MEX 得分 1，其余按 sum 得 2，答案 4。
代码：sum 加上零的个数。

## B. Pathless
[原题](https://codeforces.com/contest/2130/problem/B) | [b.cpp](b.cpp)

数组元素仅为 0,1,2，且三种均出现。行走者从下标 1 出发，每步左右移动一格，最终到 n，累计所有访问位置的数值（含重复访问及起终点），希望总和等于 s。可重排数组以使其无法做到。输入 n,s 和数组；输出任意阻止目标的重排，或 -1。
代码：总和记 S；s<S 或 s=S+1 时输出所有 0、2、1 分块，否则 -1。

## C. Double Perspective
[原题](https://codeforces.com/contest/2130/problem/C) | [c.cpp](c.cpp) | [c1.cpp](c1.cpp)

给定 n 个整数端点对 (a,b)，同时表示数轴区间 [a,b] 和无向边 a—b。选一个子集，最大化区间并集长度减去处在长度至少 3 的简单环上的不同顶点数。输入端点对；输出所选数量及原下标。
代码：c 用显式栈尝试 DFS 删环边；c1 使用并查集并检查新增覆盖。已有版本不保证正确。

## D. Stay or Mirror
[原题](https://codeforces.com/contest/2130/problem/D) | [d.cpp](d.cpp)

给定 1..n 的排列 p，对每个 i 独立选择保留 p_i 或改成 2n-p_i。求最终数组的最小逆序对数。输入多组，每组 n 与排列；输出最小逆序对数。
例：p=[2,1]，把末项变为 3 得 [2,3]，答案 0。
代码：先统计逆序，再尝试按位置调整翻转状态；未验证。标准观察是每对逆序贡献只由较小的原值是否翻转决定，可按每个元素独立比较左右较大元素数。

## E
[e.cpp](e.cpp) 仅为空 solve 框架，不能证明已做过；[本场 E 原题入口](https://codeforces.com/contest/2130/problem/E)。