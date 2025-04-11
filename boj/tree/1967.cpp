#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;
vector<bool> visit(MAX,0);
vector<pair<int,int>> graph[MAX];
pair<int,int> leaf = {0,0};
void dfs(int node, int dist){
    visit[node] = true;
    if(leaf.second<dist){
        leaf={node, dist};
    }
    for(pair<int,int> next : graph[node]){
        if(visit[next.first]){
            dfs(next.first,dist + next.second);
        }
    }
}

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    
    for(int i=0;i<n;i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[v].push_back({u,w});
        graph[u].push_back({v,w});
    }
    
    dfs(1,0);
    fill(visit.begin(),visit.end(),0);
    dfs(leaf.first,0);
    cout << leaf.second;
    return 0;
}