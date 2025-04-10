#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;
vector<bool> visit(MAX,0);
vector<pair<int,int>> graph[MAX];
pair<int,int> dfs(int node, int dist){
    if(!visit[node]){
        return {node};
    }
    for(pair<int,int> n : graph[node]){
        dfs(n.first,n.second);
    }
    return dist;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[v][u] = w;
        graph[u][v] = w;
    }

    dfs(dfs(1));

    return 0;
}