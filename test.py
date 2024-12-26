def dfs(graph, node, end, reachable, visited):
    if node == end:  # 목표 노드에 도달하면 탐색 성공
        reachable.add(node)
        return True
    visited[node] = True
    check = False
    for neighbor in graph[node]:
        # 다른 경로에서 도달 가능성을 열어두기 위해 이미 방문한 노드라도 탐색 가능
        if not visited[neighbor] or neighbor not in reachable:
            check = dfs(graph, neighbor, end, reachable, visited)
            if check:  # 탐색 성공 시 현재 노드를 reachable에 추가
                reachable.add(node)
    visited[node] = False  # 백트래킹: 현재 경로에서 방문 상태 복구
    return check

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

# 그래프 입력
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)

# 시작과 끝 노드 입력
start, end = map(int, input().split())

# Start에서 End로 도달 가능한 양방향 노드 찾기
reachable = set()
visited = [False] * (n + 1)
dfs(graph, start, end, reachable, visited)

# 시작점과 끝점 제거
reachable.discard(start)
reachable.discard(end)

# 결과 출력
print(reachable)
