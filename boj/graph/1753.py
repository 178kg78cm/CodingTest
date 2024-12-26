import sys
import heapq

INF = int(1e9)

def dijkstra(start, graph, distance):
    pq = []  # 우선순위 큐
    heapq.heappush(pq, (0, start))  # (거리, 현재 노드)
    distance[start] = 0

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        # 이미 처리된 경우 스킵
        if distance[current_node] < current_distance:
            continue

        # 인접 노드 확인
        for next_node, weight in graph[current_node]:
            new_distance = current_distance + weight
            if new_distance < distance[next_node]:
                distance[next_node] = new_distance
                heapq.heappush(pq, (new_distance, next_node))


if __name__ == "__main__":
    input = sys.stdin.readline

    # 첫 줄: 정점(V), 간선(E)
    V, E = map(int, input().split())

    # 시작 정점
    start = int(input())

    # 그래프 초기화
    graph = [[] for _ in range(V + 1)]
    for _ in range(E):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))

    # 거리 테이블 초기화
    distance = [INF] * (V + 1)

    # 다익스트라 실행
    dijkstra(start, graph, distance)

    # 결과 출력
    answer = [distance[i] if distance[i] != INF else 'INF' for i in range(1, V + 1)]
    print(*answer,sep='\n')
