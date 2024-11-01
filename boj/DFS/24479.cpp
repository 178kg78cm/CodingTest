#include <iostream>
#include <algorithm>
#include <vector>
/*
dfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    for each x ∈ E(R)  # E(R) : 정점 R의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
        if (visited[x] = NO) then dfs(V, E, x);
}*/
using namespace std;
int n, m, r;
vector<int> graph[100001];
bool visited[100001];
int order=0;
int history[100001];

void dfs(int node){
    visited[node]=1;
    order++;
    history[order]=node;
    for(auto nodes:graph[node]){
        if(!visited[nodes]){
            dfs(nodes);
        }
    }   
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int v, u;

    cin >> n >> m >> r;

    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 노드
    }
    for(int i=0;i<n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(r);

    for(int i=1;i<=order;i++){
        cout << history[i] << '\n';
    }
    return 0;
}