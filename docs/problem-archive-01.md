# 刷题史料索引（第一批：2025-04 至 2025-11）

整理日期：2026-11-26。基于 main 分支原始代码逐文件阅读；不改动原代码。
本次清点：87 个日期目录，312 个 C/C++/Python 等源文件（含模板、草稿及重复版本）。本页只覆盖第一批已阅读且可辨识的题目，不代表全仓完成。

## 使用约定

- 日期是目录记录日期，不等于原比赛日期或代码原创日期。
- 题面采用独立中文题意摘要及原题链接，不整篇转载。题号匹配以代码输入输出、文件名和比赛日期交叉核对；通用模板类题号可能不唯一。
- 文件名后缀不证明实际修改顺序。代码存在不等于 AC；没有提交记录时不得标为通过。
- 代码风格差异、模板复用不能证明 AI 使用或独立原创。备份版本及来源待核材料不得直接归因给作者。
- 小说使用时另行脱敏；不把现实团队成绩、姓名、具体日期直接套入虚构时间线。

## 题目索引

| 日期目录/代码（相对于 solutions/） | 原题 | 题意摘要 | 原代码思路及待核事项 |
| --- | --- | --- | --- |
| [250420/c.cpp](../solutions/250420/c.cpp) | [洛谷 P1115 最大子段和](https://www.luogu.com.cn/problem/P1115)（高度吻合的候选） | 求非空连续子数组的最大和 | max0 表示以当前位置结尾的最大和，max1 维护全局答案；线性 DP。模板题无法仅凭代码唯一识别。 |
| [250420/d.cpp](../solutions/250420/d.cpp) | [P1314 聪明的质监员](https://www.luogu.com.cn/problem/P1314) | 选重量阈值 W；各区间内合格物品数量乘价值和再累加，令结果尽量接近 S | 两套前缀和+阈值二分；末尾手动计算两侧候选，O((n+m)log W)。 |
| [250420/e.cpp](../solutions/250420/e.cpp) | [P1638 逛画展](https://www.luogu.com.cn/problem/P1638) | 求覆盖全部 m 类的最短连续区间 | set 判断首次覆盖，频次数组维护窗口，左端冗余时收缩；保存每个候选区间，再找最短。 |
| [250420/f.cpp](../solutions/250420/f.cpp) | [P3406 海底高铁](https://www.luogu.com.cn/problem/P3406) | 按访问城市顺序统计经过的铁路段，在单次票与办卡方案中择便宜者 | 差分累计每段经过次数，最后逐段 min(a*c,b*c+固定费)。检查 d[n-1] 未初始化但可能被读写的问题；不据此判 AC。 |
| [250424/a.cpp](../solutions/250424/a.cpp) | [CF 2106A Dr. TC](https://codeforces.com/contest/2106/problem/A) | 对原二进制串分别翻转一位，统计生成的 n 个串中 1 的总数 | 不生成矩阵；直接 ones*(n-1)+zeros。O(n)。 |
| [250424/b.cpp](../solutions/250424/b.cpp) | [CF 2106B St. Chroma](https://codeforces.com/contest/2106/problem/B) | 排列 0..n-1，使前缀 MEX 等于指定 x 的次数最大 | 先输出小于 x 的数，再倒序输出其余数，让 x 尽量靠后。 |
| [250424/c.cpp](../solutions/250424/c.cpp) | [CF 2106C Cherry Bomb](https://codeforces.com/contest/2106/problem/C) | 补全 b 的未知项（0..k），要求每个 a_i+b_i 相同，计数 | 有已知项则共同和被锁定；全未知则数共同和区间 [max(a), k+min(a)] 的整数数目。 |
| [250424/d.cpp](../solutions/250424/d.cpp) | [CF 2106D Flower Boy](https://codeforces.com/contest/2106/problem/D) | 顺序挑选满足各自最低美丽值的 m 朵花，可至多插入一朵，求其最小必要值或判定无需/不可能 | 正反两次贪心匹配，尝试拼接前后缀；有 cerr 调试；反向填充写入 c 而非 d、候选未显式取 min 等风险，需测试。 |
| [250426/g.cpp](../solutions/250426/g.cpp) | [P1036 选数](https://www.luogu.com.cn/problem/P1036) | 从 n 个数选择 k 个，统计和为质数的组合数 | 递归返回所有组合和的 vector，使用递增下标避免重复，再筛素数试除；复制和合并开销较大，和为 1 时判断存在漏洞。 |
| [250426/h.cpp](../solutions/250426/h.cpp) | [P2085 最小函数值](https://www.luogu.com.cn/problem/P2085) | 给定若干二次函数，求正整数自变量产生的最小 m 个值（保留重数） | 每个函数形成递增数列，用小根堆保存各列首个未输出元素，弹出后补入下一项。 |
| [250717/h.cpp](../solutions/250717/h.cpp)、[h.py](../solutions/250717/h.py)、[h1.py](../solutions/250717/h1.py) | [Gym 105937H 9-Nine](https://codeforces.com/gym/105937/problem/H) | 两个 3×3 01 矩阵，可独立旋转或交换对应列；81 步内变成 A 全 0、B 全 1 | C++ 空壳；Python 随机生成满足中心、边、角总数约束的局面，支持手动操作；另一 Python 实现按中心、边、角分阶段构造，记录操作。未验证终止性及步数。 |
| [250717cf/c.cpp](../solutions/250717cf/c.cpp)、[c1.cpp](../solutions/250717cf/c1.cpp) | [CF 2126C I Will Definitely Make It](https://codeforces.com/contest/2126/problem/C) | 水位随时间上涨，从一座塔传送到另一座塔耗时为高度差，能否到最高塔 | c 排序后逐步跳到下一个更高高度；c1 用 BFS 但错误限制相邻下标并逐时间模拟。两个版本来源/顺序未核实。 |
| [250717cf/d.cpp](../solutions/250717cf/d.cpp)、[d2.cpp](../solutions/250717cf/d2.cpp) | [CF 2126D This Is the Last Time](https://codeforces.com/contest/2126/problem/D) | 初始 k，若钱数在赌场允许区间则可变为指定值；每处最多一次，求最大最终值 | d 重复扫描可用区间，选择最大 real，可能下降且有 O(n²) 风险；d2 尝试坐标压缩+线段树，不确认正确性与作者归属。标准思路可利用 l≤real≤r 的单调性只做增益。 |
| [250719cf/c.cpp](../solutions/250719cf/c.cpp)、[c1.cpp](../solutions/250719cf/c1.cpp) | [CF 2122C Manhattan Pairs](https://codeforces.com/contest/2122/problem/C) | 偶数个平面点两两配对，使曼哈顿距离和最大 | c 按 x+y、x-y 两套排序，尝试反复选当前最远点对；有末轮指针越界风险，局部最远不保证全局最优。c1 枚举多种排序配法，不保证最优。 |
| [250731cf/c.cpp](../solutions/250731cf/c.cpp)、[c1.cpp](../solutions/250731cf/c1.cpp) | [CF 2130C Double Perspective](https://codeforces.com/contest/2130/problem/C) | 每个整数区间同时当作无向边，选子集最大化区间覆盖长度减去环上节点数 | c 手写显式栈 DFS 标记删边；c1 尝试 DSU 及覆盖标记。可用生成森林保留全部区间并集且消去环；两版是否正确及来源待核。 |
| [250808/a.cpp](../solutions/250808/a.cpp)、[a.py](../solutions/250808/a.py)、[a1.cpp](../solutions/250808/a1.cpp) | [P1495 中国剩余定理/曹冲养猪](https://www.luogu.com.cn/problem/P1495)（候选） | 两两互质模数下的同余方程组，求最小非负解 | CRT+扩展欧几里得；同时存有 long long、Python 大整数、__int128 手写输出版本。可用于溢出教学，不能断言版本先后。 |
| [251009/P3865_1.cpp](../solutions/251009/P3865_1.cpp)、[P3865_2.cpp](../solutions/251009/P3865_2.cpp) | [P3865 ST 表与 RMQ](https://www.luogu.com.cn/problem/P3865) | 静态数组多次区间最大值询问，题目要求 O(1) 查询 | _1 使用带 lazy 的线段树，查询 O(log n)；_2 稀疏表预处理 O(n log n)，查询 O(1)。文件中线段树注释残留区间和字样。 |
| [251009/p1908_1.cpp](../solutions/251009/p1908_1.cpp)、[p1908_2.cpp](../solutions/251009/p1908_2.cpp) | [P1908 逆序对](https://www.luogu.com.cn/problem/P1908) | 统计 i<j 且 a_i>a_j 的数对数量 | 归并计数 vs 按值降序、同值下标降序后用树状数组计数；均 O(n log n)。模板来源待核。 |
| [251009/24shengyangICPC_G.py](../solutions/251009/24shengyangICPC_G.py) | [Gym 105578G Guess the Polygon](https://codeforces.com/gym/105578/problem/G) | 顶点次序打乱，至多 n-2 次查询竖直截线长度，求多边形面积的精确分数 | 按 x 坐标分组，构造查询并外推端点截线长度，以梯形面积累加；文件明确自记 CF WA test4、QOJ RE test4。Python int(p/c) 经过浮点，存在精度风险；查询策略等仍待查。 |
| [251018/XianB.cpp](../solutions/251018/XianB.cpp) | [P14445 ICPC 2025 Xi'an Practice Follow the Sequence](https://www.luogu.com.cn/problem/P14445) | 无限重复一段平面移动指令，统计能走到的给定关键点数 | 记录周期内位置；设周期净位移 (x,y)，整数矩阵把重复移动转成横向平移，按纵坐标与横坐标模 x²+y² 分组，保存最小横坐标。零位移特判；固定偏移 2e10 不能普遍保证余数非负，应验证。 |
| [251114/25harbinwarmup_a.cpp](../solutions/251114/25harbinwarmup_a.cpp) | [Gym 106184A 秘术「天文密葬法」](https://codeforces.com/gym/106184/problem/A) | 给出可能有数百万位的 n!/m，已知 1≤m<n≤10^6，反求 n,m | 对阶乘取 log10 前缀和；用位数和头部数字近似 log10 输入，再二分 n，指数还原 m 并四舍五入。浮点误差和边界待检验。 |

## 小说素材候选（基于代码可观察行为，非真实对话）

1. **9-Nine（暑训）**：真实 Galgame 背景题；主角写 Python 手动棋盘模拟器，试转动、交换，再总结三类格子不变量。可结合训练室魔方，不需要让队友口头灌输整个算法。H.cpp 空壳及两个 Python 文件体现尝试过程。可做成可选交互小游戏；不直接复刻原作角色、剧情或素材。
2. **Follow the Sequence（较后期训练）**：二维无限运动化为整数坐标变换及同余分类。对点 (a,b)，令 u=xa+yb, v=-ya+xb。周期位移 (x,y) 使 u 增加 x²+y²，v 不变。以 (v,u mod D) 为键保留最小 u；查询只需同类且在起点之后。体现数学直觉+map 的结合；与早期逆康托形成呼应。
3. **Manhattan Pairs（暑训挫折）**：原代码意识到 |dx|+|dy|=max(|dx+dy|,|dx-dy|)，但把找最远点对当作最大权完美匹配的贪心策略。让 CSB 给反例，再讨论横纵坐标分别分半及交叉配对的全局最优证明。不要把未证算法写成 AC。
4. **Guess the Polygon（VP/补题候选）**：通过竖直截线对面积做分段梯形积分；作者自己记下两个 OJ 不同失败结果。适合表现数学能力与实现严谨性并不相同，且可自然引出交互题、flush、分数精确运算。修复/结局未获史料确认。
5. **秘术「天文密葬法」（赛前练习）**：五百多万位整数不适合直接算阶乘，代码选择对数，把超大数字变成可二分的小量。适合表现主角从数学角度避开计算量；不保证原代码数值精度完全正确。
6. **CRT（专题练习）**：long long 溢出风险在原注释中明确存在，并有 Python 与 __int128 版本；可作为实际工具取舍。不能把模板公式视为主角自行发明。
7. **CF 2106（首次 CF 或早期训练候选）**：A 用计数公式取代矩阵，B 用构造，C 用区间交集，D 留下前后缀匹配和调试痕迹。很适合作为一场由顺利到卡题的练习，但不能仅凭仓库断言这是作者首次 CF 或真实掉分场次。
8. **P1036（早期训练）**：从高程全排列的数学编号方法转向递归生成所有组合和，甚至仍以 vector 返回完整结果，体现理解了递归但还没习惯在叶子直接计数。须注明算法来源未核实。
9. **P1908（回收高程插入排序）**：从相邻交换次数理解逆序对，再对照归并和树状数组。适合作为章节末算法小课堂，而非强行在剧情中解释两套完整模板。

## 未完成工作

- 未识别全部 87 个日期目录的比赛及题号；特别是仅有 a.cpp/b.cpp 的 VP/多校目录需用代码指纹、OJ 提交记录或题面交叉确认。
- 未核验所有源文件的 AC/WA/TLE、作者身份、队友贡献、题解/AI 来源、版本顺序；不据此推断真实 rating 或正式比赛结果。
- 2026 年春季 VP 及 book、templates 等未全面整理。
- 本页仅为新增史料索引，未修改原始代码，也未将小说候选正式写入剧情。
