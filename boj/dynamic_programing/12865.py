import sys
input = sys.stdin.readline


N, K = map(int, input().strip().split())

# N개의 물품 정보를 저장할 리스트
items = []
for _ in range(N):
    W, V = [list[map(int, input().strip().split())]]
    items.append((W, V))

back = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(N+1):
    for j in range(K+1):
        weight = items[i][0] 
        value = items[i][1]
       
        if j < weight:
            back[i][j] = back[i - 1][j] #weight보다 작으면 위의 값을 그대로 가져온다
        else:
            back[i][j] = max(value + back[i - 1][j - weight], back[i - 1][j])

print(back[N][K])