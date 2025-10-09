import heapq
import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        graph = [[] for _ in range(n + 1)]
        for _ in range(m):
            u = int(data[index])
            v = int(data[index + 1])
            index += 2
            graph[u].append(v)
            graph[v].append(u)
        
        deg = [0] * (n + 1)
        for i in range(1, n + 1):
            deg[i] = len(graph[i])
        
        INF = 10**18
        dist = [None] * (n + 1)
        for i in range(1, n + 1):
            dist[i] = [(INF, INF)] * deg[i]
        
        pq = []
        if deg[1] > 0:
            dist[1][0] = (0, 0)
            heapq.heappush(pq, (0, 0, 1, 0))
        
        while pq:
            T, W, u, r = heapq.heappop(pq)
            if (T, W) != dist[u][r]:
                continue
            
            new_r1 = (r + 1) % deg[u]
            new_T1 = T + 1
            new_W1 = W + 1
            if new_T1 < dist[u][new_r1][0] or (new_T1 == dist[u][new_r1][0] and new_W1 < dist[u][new_r1][1]):
                dist[u][new_r1] = (new_T1, new_W1)
                heapq.heappush(pq, (new_T1, new_W1, u, new_r1))
            
            if deg[u] == 0:
                continue
            v = graph[u][r]
            new_T2 = T + 1
            new_r_v = new_T2 % deg[v]
            new_W2 = W
            if new_T2 < dist[v][new_r_v][0] or (new_T2 == dist[v][new_r_v][0] and new_W2 < dist[v][new_r_v][1]):
                dist[v][new_r_v] = (new_T2, new_W2)
                heapq.heappush(pq, (new_T2, new_W2, v, new_r_v))
        
        bestT = INF
        bestW = INF
        for r in range(deg[n]):
            t_val, w_val = dist[n][r]
            if t_val < bestT:
                bestT = t_val
                bestW = w_val
            elif t_val == bestT:
                if w_val < bestW:
                    bestW = w_val
        
        results.append(f"{bestT} {bestW}")
    
    print("\n".join(results))

if __name__ == "__main__":
    main()