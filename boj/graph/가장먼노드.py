'''
제한사항
노드의 개수 n은 2 이상 20,000 이하입니다.
간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.
입출력 예
n	vertex	return
6	[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	3
'''
from collections import deque

n = int(input())
graph = [[] for _ in range(n)]
for i in range (n):
    u, v = map(int(input().split))
    graph[u].append(v)
    graph[v].append(u)
    
list1 = [0] * 6
dq = deque()
dq.append(1)
dist = 1

while not dq:
    target = dq.popleft()
    for node in graph[target]:
        dq.append(node)
        if list1[node] == 0:
            list1[node] = dist+1
    dist+=1
    
maxlist = list1[lambda x : x == dist]

print(list1.count(dist))