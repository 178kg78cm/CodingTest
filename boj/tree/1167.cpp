#include <vector>
#include <iostream>

using namespace std;
vector<vector<pair<int,int>>> graph;
vector<bool> visited;
pair<int,int> max_node;
void dfs(int node, int dist){
    visited[node] = 1;
    if(max_node.second < dist){
        max_node = {node,dist};
    }
    for(pair<int,int> next_node : graph[node]){
        if(!visited[next_node.first]){
            dfs(next_node.first, dist + next_node.second);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    graph.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<n;i++){
        int u;
        cin >> u;
        while(1){
            int v;
            cin >> v;
            if(v==-1){
                break;
            }
            int w;
            cin >> w;
            graph[u].push_back({v,w});
        }
    }

    dfs(1,0);
    fill(visited.begin(),visited.end(),0);
    dfs(max_node.first,0);

    cout << max_node.second;
    return 0;
}