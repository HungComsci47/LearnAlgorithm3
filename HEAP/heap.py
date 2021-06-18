from queue import PriorityQueue

a = [7, 12, 6, 10, 15, 2, 4]
pq = PriorityQueue()
for x in a:
    pq.put(-x)

while not pq.empty():
    u = pq.get()
    print(abs(u))
