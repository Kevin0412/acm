# Educational Codeforces Round 180 (Div. 2) — CF 2112
[原比赛题面](https://codeforces.com/contest/2112/problems)。中文摘要；完整约束与官方样例见原站。

## A. Race
[原题](https://codeforces.com/contest/2112/problem/A) · [a.cpp](a.cpp)

Alice 在数轴点 a，奖品可能出现在 x 或 y。Bob 可选择不同于 a 的任意整数点，问是否能保证比 Alice 更近。每组输入互异 a,x,y，输出 YES/NO。
代码判断 a 是否位于 x,y 之间；两奖品在同侧时向该侧走一步即有解。

## B. Shrinking Array
[原题](https://codeforces.com/contest/2112/problem/B) · [b.cpp](b.cpp)

每次将相邻两个数替换为其闭区间内任意整数。若数组至少有两项且某相邻差绝对值不超过 1，则为美丽数组。求最少操作次数，不可能输出 -1。每组输入 n（2..1000）与数组。
代码：已有相邻差≤1 则 0；若所有相邻差均大于 1 且出现方向反转，则可做一次合并；严格单调则 -1。
自拟例：[2,7,3] 合并 2,7 为 3，答案 1。

## C. Coloring Game
[原题](https://codeforces.com/contest/2112/problem/C) · [c.cpp](c.cpp)

Alice 选三个元素染红，Bob 任意选一个元素染蓝（若原为红则取消其红色）。Alice 要保证剩余红色元素之和严格大于蓝色值。统计可保证获胜的三元下标组。
每组输入 n（3..5000）与非降序正整数数组，输出方案数。代码固定后两项 j,k，再二分第一项的最小允许值，条件为第一项严格大于 max(全局最大值-a[j]-a[k],a[j]-a[k])。复杂度 O(n² log n)，ans 使用 int 可能溢出，未验证提交结果。

## D. Reachability and Tree
[原题](https://codeforces.com/contest/2112/problem/D) · [d.cpp](d.cpp)

给一棵 n 点无向树，为每条边定向，使存在有向路径的不同顶点有序对恰有 n 个。输出 NO 或 YES 以及 n-1 条有向边。
代码：寻找度数恰好为 2 的点，令它一入一出，其余点沿树两侧交替作为纯源/纯汇，制造恰好一条长度 2 的有向路径。若找不到度 2 点则无解。递归深度风险待核。
自拟例：三点链 1→2→3，共 (1,2),(2,3),(1,3) 三对。