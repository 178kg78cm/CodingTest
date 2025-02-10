#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, m;
vector<int> graph[1001];
bool visited[1001] = {0,};
int num=0;
bool dfs(int parent, int pparent){
    if(visited[parent]){
        return false;
    }
    visited[parent] = 1;
    num++;
    bool valid = 1;
    for(auto node : graph[parent]){
        if(node == pparent) continue;
        if(!dfs(node, parent)) valid = 0;
    }

    return valid;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> t;

    while(t--){
        cin >> n >> m;
        fill(visited, visited+1001,0);
        for(int i=0;i<=n;i++){
            graph[i].clear();
        }
        num = 0;
        for(int i=0;i<m;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(dfs(1, -1)&&num==n){
            cout << "tree\n";
        } else cout << "graph\n";
    }

    return 0;
}