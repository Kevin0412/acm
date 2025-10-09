from math import gcd
from typing import List

def exgcd(a: int, b: int) -> (int, int, int):
    if b == 0:
        return a, 1, 0
    d, x, y = exgcd(b, a % b)
    return d, y, x - (a // b) * y

def crt(r: List[int], a: List[int]) -> int:
    n = 1
    for x in r:
        n *= x
    ans = 0
    for i in range(len(a)):
        m = n // r[i]
        _, R, _ = exgcd(m, r[i])
        ans = (ans + a[i] * m * R) % n
    return (ans % n + n) % n

def main():
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        ai, bi = map(int, input().split())
        a.append(ai)
        b.append(bi)
    print(crt(a, b))

if __name__ == "__main__":
    main()