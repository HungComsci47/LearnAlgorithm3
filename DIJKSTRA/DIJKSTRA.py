#INPUT:
#5 6
#1 2 2
#2 5 5
#2 3 4
#1 4 1
#4 3 3
#3 5 1
#OUTPUT:
#1 4 3 5 
from heapq import *
MAX_N = 100005
inf = int(1000000000007)
dist = [inf for i in range(MAX_N)]
trace = [-1 for _ in range(MAX_N)]
adj = [[] for _ in range(MAX_N)]
def Dijkstra(start):
    pq = []
    dist[start] = 0
    heappush(pq, (0, 1))
    while pq:
        distance, u = heappop(pq)
        if distance != dist[u]:
            continue
        if u == n:
            break
        for neighbor in adj[u]:
            v, w = neighbor
            if dist[v] > distance + w:
                dist[v] = distance + w
                heappush(pq, (dist[v], v))
                trace[v] = u

def findPath():
    if dist[n] == inf:
        print(-1)
        return
    u = n
    res = []
    while u != -1:
        res.append(u)
        u = trace[u]
    res.reverse()
    for i in range(len(res)):
        print(res[i], end=' ')


if __name__ == '__main__':
    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))
    Dijkstra(1)
    findPath()
