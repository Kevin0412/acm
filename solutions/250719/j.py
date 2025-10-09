import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    out_lines = []
    for _ in range(t):
        n = int(data[index])
        index += 1
        s = data[index]
        index += 1
        edges = []
        for i in range(n - 1):
            u = int(data[index])
            v = int(data[index + 1])
            index += 2
            edges.append((u, v))
        
        deg = [0] * (n + 1)
        for (u, v) in edges:
            deg[u] += 1
            deg[v] += 1
        
        index_ptr = [0] * (n + 2)
        for i in range(1, n + 1):
            index_ptr[i] = index_ptr[i - 1] + deg[i - 1]
        total_edges = 2 * (n - 1)
        graph = [0] * total_edges
        
        for i in range(1, n + 1):
            deg[i] = index_ptr[i]
        
        for (u, v) in edges:
            pos_u = deg[u]
            graph[pos_u] = v
            deg[u] = pos_u + 1
            pos_v = deg[v]
            graph[pos_v] = u
            deg[v] = pos_v + 1
        
        del deg
        del edges
        
        totalS = [0] * (n + 1)
        totalC = [0] * (n + 1)
        for i in range(1, n + 1):
            start = index_ptr[i]
            end = index_ptr[i + 1]
            for j in range(start, end):
                neighbor = graph[j]
                if s[neighbor - 1] == 'S':
                    totalS[i] += 1
                if s[neighbor - 1] == 'C':
                    totalC[i] += 1
        
        ans = 0
        for i in range(1, n + 1):
            if s[i - 1] != 'C':
                continue
            T_val = 0
            U_val = 0
            start = index_ptr[i]
            end = index_ptr[i + 1]
            for j in range(start, end):
                neighbor = graph[j]
                if s[neighbor - 1] == 'C':
                    T_val += totalS[neighbor]
                elif s[neighbor - 1] == 'P':
                    U_val += (totalC[neighbor] - 1)
            ans += T_val * U_val
        out_lines.append(str(ans))
    
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()