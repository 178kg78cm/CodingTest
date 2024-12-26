#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
bool history[100001];
int order=0;
/*
bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    for each v ∈ V - {R}
        visited[v] <- NO;
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
    while (Q ≠ ∅) {
        u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
        for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
            if (visited[v] = NO) then {
                visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
                enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
            }
    }
}
*/

void bfs(int start){
    queue<int> list;
    history[start]=order++;
    list.push(start);
    visited[start]=1;
    
    
    while(!list.empty()){
        int node = list.front();
        list.pop();

        for(int nodes:graph[start]){
            if(!visited[nodes]){
                visited[nodes] = 1;
                history[nodes] = order++;
                list.push(nodes);
            }
        }
    }

}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m,r;

    cin >> n >> m >> r;

    while(m--){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    bfs(r);

    for(int i=1;i<=n;i++) cout << history[i] << '\n';
    return 0;
}