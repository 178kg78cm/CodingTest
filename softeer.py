def dfs(graph, node, target, visited, reachable):
    if node == target:  # 목표 노드에 도달하면 탐색 중단
        reachable.add(node)
        return
    visited[node] = True
    reachable.add(node)
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(graph, neighbor, target, visited, reachable)

n, m = map(int, input().split())

# 그래프 초기화
graph = [[] for _ in range(n + 1)]

# 그래프 입력
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)

# 시작과 끝 노드 입력
start, end = map(int, input().split())

# 1. Start에서 도달 가능한 노드 찾기
reachable_from_start = set()
visited = [False] * (n + 1)
dfs(graph, start, end, visited, reachable_from_start)

# 2. End에서 도달 가능한 노드 찾기 (역방향 탐색)
reachable_from_end = set()
visited = [False] * (n + 1)
dfs(graph, end, start, visited, reachable_from_end)

# 3. 교집합 계산
common_nodes = reachable_from_start & reachable_from_end
common_nodes.discard(start)
common_nodes.discard(end)

# 4. 결과 출력
print(len(common_nodes))
