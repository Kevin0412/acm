# 2025-08-30 · 混合练习（部分匹配）

## 2024 ICPC 成都区域赛 L. Recover Statistics
[洛谷 P15083](https://www.luogu.com.cn/problem/P15083) · [Gym 105486L](https://codeforces.com/gym/105486/problem/L) · [Untitled-1.cpp](Untitled-1.cpp)

给定通勤数据的 P50、P95、P99 值 a,b,c（1≤a<b<c<10^9），构造 100..10^5 个 1..10^9 范围内的整数，使恰有 50%、95%、99% 的数分别不超过 a,b,c。输出数量与数据。
代码固定构造 100 项：50 个 a、45 个 b、4 个 c、1 个 c+1。恰好分别有 50、95、99 项不超过三个阈值。O(1) 固定输出长度。题面匹配已确认，提交状态未查。
自拟例：a=2,b=4,c=6，按上述频次输出即可。

## 尚未定位原题
- [Untitled-2.cpp](Untitled-2.cpp)、[Untitled-3.cpp](Untitled-3.cpp)：关卡切换和完成/退出事件，按完成次序分配积分，输出排名；两版行为不同。
- [Untitled-4.cpp](Untitled-4.cpp)：寻找最小二次幂 i 使 floor(a/i)=floor(b/i)，输出 a mod i。
数字文件与成都站 L 的匹配不代表其余文件属于同一比赛，不据此强行分配题号。


## 2024 CCPC 郑州站 A. A + B = C Problem
[官方题面 Gym 105632A](https://codeforces.com/gym/105632/problem/A) · [Untitled-5.cpp](Untitled-5.cpp)

给三个最小正周期 p_A,p_B,p_C，构造三个无限二进制周期串，使 A XOR B=C，或判断无解。多组，T≤10^4，各周期≤10^6，所有组最大周期之和≤10^6。输出 YES 及三个周期块，或 NO。

代码将周期升序为 a,b,c，若 lcm(a,b)=c 且不是 a=b=2，则构造两个稀疏周期串并取逐位 XOR，最后按原输入次序输出。该条件过强，不是一般必要条件。例如周期 6,10,15 可用三个最小周期为 2,3,5 的单脉冲序列 U,V,W，构造 A=U XOR V、B=U XOR W、C=V XOR W，分别具有最小周期 6,10,15，且 A XOR B=C；原代码却输出 NO。更一般的必要条件是任意两周期的 LCM 都必须能被第三个周期整除；这个必要条件本身不保证所有退化情况可构造。代码 lcm 使用 int 也存在乘积溢出风险。
题意已与正式单题页面核对，原代码保留，未查询提交结果。
