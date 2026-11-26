# 250629 题目档案

本页由已有史料索引按日期归档，保留题号匹配、候选标注和原始解法笔记。中文摘要非官方全文；完整限制及样例见原题链接。未记录 AC 状态。

## 1. [Gym 105981C Echoes of the Runes](https://codeforces.com/gym/105981/problem/C)

原始代码：[c.cpp](c.cpp)

数组能否至多交换两元素一次变为非降序；代码试图根据下降位置找交换点，未处理单个下降（如 2,1），且 temp==-2 是比较而非赋值。

[整理来源](../../docs/problem-archive-02.md)

## 2. [105981D Keine's Prefix Sum](https://codeforces.com/gym/105981/problem/D)

原始代码：[d.cpp](d.cpp)

统计所有循环移位中前缀和始终非负的数量；从负值向前累加并排除起点，原算法正确性未验证；可对照双倍前缀和与滑动最小值。

[整理来源](../../docs/problem-archive-02.md)

## 3. [105981E Neuro's New Game](https://codeforces.com/gym/105981/problem/E)

原始代码：[e.cpp](e.cpp)

根据环形二进制串构造排列，使相邻元素满足指定大小关系。尝试从两端分配数值和处理环首尾；sum 未初始化，未验证。题目以 Neuro-sama 和音游为背景。

[整理来源](../../docs/problem-archive-02.md)

## 4. [105981F Portal](https://codeforces.com/gym/105981/problem/F)

原始代码：[f.cpp](f.cpp)

房间各有若干成对传送门，任意配对是否必然使首尾连通。代码直接判断首尾奇数、中间偶数（n=1 特判）。奇偶度数定理：连通分量的奇度点总数为偶数，因此仅首尾奇度时无法分开；其他情况可构造分离。

[整理来源](../../docs/problem-archive-02.md)

## 5. [105981H Simai](https://codeforces.com/gym/105981/problem/H)

原始代码：[h.cpp](h.cpp)

舞萌 DX 八等分圆周上的滑键长度。直接预先算好弦长常量、弧长单位，按模 8 的差值分类；同点圆弧等边界以原题定义为准。

[整理来源](../../docs/problem-archive-02.md)

## 6. [105981J Uniform Random Descent Process](https://codeforces.com/gym/105981/problem/J)

原始代码：[j.cpp](j.cpp)

从 n 等概率下降到 0..n-1，求到 0 的期望步数。原式 E_i=(E_(i-1)-1)(i-1)/i+E_(i-1)/i+1，等价于 E_i=E_(i-1)+1/i；保留了消去求和的推导痕迹。

[整理来源](../../docs/problem-archive-02.md)