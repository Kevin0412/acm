t = int(input().strip())
for _ in range(t):
    data = input().split()
    if not data:
        data = input().split()
    n, m, p = map(int, data)
    a = list(map(float, input().split()))
    b = list(map(float, input().split()))
    c = list(map(float, input().split()))
    
    total_oc = sum(a)
    total_kp = sum(b)
    total_xw = sum(c)
    total = total_oc + total_kp + total_xw
    avg = total / 3.0
    
    debts = [
        total_oc - avg,
        total_kp - avg,
        total_xw - avg
    ]
    
    S = 0.0
    for d in debts:
        if d > 0:
            S += d
            
    T = [[0.0] * 3 for _ in range(3)]
    
    if abs(S) > 1e-9:
        for i in range(3):
            if debts[i] < 0:
                for j in range(3):
                    if i != j and debts[j] > 0:
                        amount = (-debts[i]) * (debts[j]) / S
                        T[i][j] = amount
                        
    res = [
        T[0][1], T[0][2],
        T[1][0], T[1][2],
        T[2][0], T[2][1]
    ]
    
    formatted = [f"{x:.2f}" for x in res]
    print(" ".join(formatted))