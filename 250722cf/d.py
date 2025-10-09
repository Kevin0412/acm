MOD = 998244353
import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        print(0)
        return
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    ends = [[] for _ in range(m+1)]
    
    F = 1
    for _ in range(n):
        l = int(next(it))
        r = int(next(it))
        p = int(next(it))
        q = int(next(it))
        denom = (q - p) % MOD
        if denom < 0:
            denom += MOD
        w = p * pow(denom, MOD-2, MOD) % MOD
        if r <= m:
            ends[r].append((l, w))
        F = F * (denom * pow(q, MOD-2, MOD)) % MOD

    dp = [0] * (m+1)
    dp[0] = 1
    for r in range(1, m+1):
        total = 0
        for (l, w) in ends[r]:
            if l - 1 >= 0:
                total = (total + dp[l-1] * w) % MOD
        dp[r] = total

    ans = F * dp[m] % MOD
    print(ans)

if __name__ == "__main__":
    main()