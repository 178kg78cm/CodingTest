#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int V,E;
        cin >> V >> E;
        vector<int> graph[V];
        for(int i=0;i<E;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i=0;i<V;i++){
            
        }

    }



}