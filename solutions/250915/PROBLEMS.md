# Educational Codeforces Round 182 (Div. 2) — CF 2144

[比赛原题](https://codeforces.com/contest/2144)。中文摘要；原代码状态不代表 AC。

## A. Cut the Array
[原题](https://codeforces.com/contest/2144/problem/A) | [a.cpp](a.cpp)

给非负整数数组，选择 1≤l<r<n 切成三个非空连续段。要求各段和模 3 后，要么全部相同，要么全部不同。输入多组，每组 n（3..40）和数组；输出 l,r，若无解输出 0 0。
代码只检查总和是否能被 3 整除，若能则直接切 1,2。事实上三个余数的和模 3 为 0 当且仅当全同或全异，所以任意合法切法均可；否则无解。

## B. Maximum Cost Permutation
[原题](https://codeforces.com/contest/2144/problem/B) | [b.cpp](b.cpp)

部分排列以 0 表示未知元素，补上缺失数字。定义代价为将整个排列变有序所需排序的最短连续区间长度，求所有补法中的最大代价。输入 n、部分排列；输出最大代价。
代码：仅一个零时恢复唯一缺失值，其余情况把零视为可错位；寻找首尾不等于其下标的位置。

## C. Non-Descending Arrays
[原题](https://codeforces.com/contest/2144/problem/C) | [c.cpp](c.cpp)

给两个长度 n 的数组 a,b，可选择任意下标集合，对其中每个 i 交换 a_i,b_i。求使两个数组均非降序的下标集合个数（模 998244353）。输入多组，每组 n 与两个数组，输出计数。
代码：先贪心找到一组合法方向，再统计相邻两列允许相对方向自由变化的次数，答案为 2 的幂。若无法相接输出 0。

## D. Price Tags
[原题](https://codeforces.com/contest/2144/problem/D) | [d.cpp](d.cpp)

n 件商品原价 c_i，每件有对应旧标签。统一选整数 x>1，把价格改为 ceil(c_i/x)。旧标签可以互换复用，不足的标签每张花费 y。求所有 x 下的最大收入（新售价总和减印标签费用）。
输入多组，每组 n,y 和 n 个原价（价格不超过 2×10^5），输出最大净收入，可为负数。
代码：频率前缀和，按每个 x 的长度 x 的价格桶计算新价格及可复用标签数，调和级数枚举。来源待核。