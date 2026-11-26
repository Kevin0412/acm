# 2025-08-04 · 杭电暑期多校第 6 场及矩阵快速幂

## 1009 对撞器
[HDU 8047](https://acm.hdu.edu.cn/showproblem.php?pid=8047) · [北交镜像](https://icpc.bjtu.edu.cn/problem/9531) · [题解核对](https://www.cnblogs.com/lyet/p/19024315) · [1009.cpp](1009.cpp)
在排列的粒子碰撞过程中最大化产生的能量。输入多组 n 和粒子能量数组，输出最大值。具体碰撞规则以原题为准（本次镜像读取超时）。
代码：n≤2 时为 0，否则 (n-3)*max(a)+max(a[0],a[n-1])。该式将最大元素在两端及在中间的情况统一起来；与公开题解吻合。

## A 矩阵快速幂
[洛谷 P3390](https://www.luogu.com.cn/problem/P3390)（候选） · [a.cpp](a.cpp)
给 n 阶矩阵 A 和非负指数 k，输出 A^k 的各元素模 10^9+7。代码实现矩阵乘法、单位矩阵、二进制快速幂。

## B 矩阵加速（数列）
[洛谷 P1939](https://www.luogu.com.cn/problem/P1939) · [b.cpp](b.cpp) · [b1.cpp](b1.cpp)
定义 a_1=a_2=a_3=1，n≥4 时 a_n=a_(n-1)+a_(n-3)。给多组 n，输出 a_n mod 10^9+7。代码用 3×3 转移矩阵快速幂，O(log n)。两个版本算法一致。