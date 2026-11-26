# 2025-08-30 · 混合练习（部分匹配）

## 2024 ICPC 成都区域赛 L. Recover Statistics
[洛谷 P15083](https://www.luogu.com.cn/problem/P15083) · [Gym 105486L](https://codeforces.com/gym/105486/problem/L) · [Untitled-1.cpp](Untitled-1.cpp)

给定通勤数据的 P50、P95、P99 值 a,b,c（1≤a<b<c<10^9），构造 100..10^5 个 1..10^9 范围内的整数，使恰有 50%、95%、99% 的数分别不超过 a,b,c。输出数量与数据。
代码固定构造 100 项：50 个 a、45 个 b、4 个 c、1 个 c+1。恰好分别有 50、95、99 项不超过三个阈值。O(1) 固定输出长度。题面匹配已确认，提交状态未查。
自拟例：a=2,b=4,c=6，按上述频次输出即可。

## 尚未定位原题
- [Untitled-2.cpp](Untitled-2.cpp)、[Untitled-3.cpp](Untitled-3.cpp)：关卡切换和完成/退出事件，按完成次序分配积分，输出排名；两版行为不同。
- [Untitled-4.cpp](Untitled-4.cpp)：寻找最小二次幂 i 使 floor(a/i)=floor(b/i)，输出 a mod i。
- [Untitled-5.cpp](Untitled-5.cpp)：三组周期二进制串的异或构造，代码按 LCM 判定，原始约束待查。
数字文件与成都站 L 的匹配不代表其余文件属于同一比赛，不据此强行分配题号。
