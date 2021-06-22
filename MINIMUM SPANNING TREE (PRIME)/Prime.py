# INPUT:
#7 11
#0 1 7
#0 3 5
#1 2 8
#1 3 9
#1 4 7
#2 4 5
#3 4 15
#3 5 6
#4 5 8
#4 6 9
#5 6 11
# OUTPUT:
# 39

from heapq import *
inf = int(1e9)
MAX_N = 100005
dist = [inf for i in range(MAX_N)]
adj = [[] for _ in range(MAX_N)]
visited = [False for _ in range(MAX_N)]

def Prime():
    mst = 0
    cnt = 0
    pq = []
    dist[0] = 0
    heappush(pq, (0, 0))
    while pq:
        d, u = heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        mst += d
        cnt += 1
        for neighbor in adj[u]:
            v,w = neighbor
            if dist[v] > w and visited[v] == False:
                dist[v] = w
                heappush(pq, (dist[v], v))
    return mst, cnt


if __name__ == '__main__':
    n, m = map(int, input().split())
    for i in range(m):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))
    mst, cnt = Prime()
    sum = 0
    #for i in range(0,v+1):
    #    sum += dist[i]
    #    print(cnt)
    if int(cnt) != int(n):
       print("DNE")
    else:
       print(mst, end=' ')
