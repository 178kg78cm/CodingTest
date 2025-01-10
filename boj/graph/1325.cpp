#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, max_connect = 0;
    cin >> n >> m;
    vector<int> graph[n+1];
    vector<int> max_hack;
    for(int i=0;i<m;i++){
        int v, w;
        cin >> v >> w;
        graph[w].push_back(v);
    } // 삽입

    for(int i=1;i<n+1;i++){
        int hack_num = 0;
        vector<bool> visited(n+1, 0);
        queue<int> q;
        q.push(i);
        int connect = 0;
        visited[i] = 1;
        while(!q.empty()){
            int nodes = q.front();
            q.pop();
            if(graph[nodes].empty()) continue;
            for(auto node : graph[nodes]){
                if(!visited[node]){
                    visited[node]=1;
                    connect++;
                    q.push(node);
                }
            }
        }
        if(max_connect < connect){
            max_connect = connect;
            max_hack.clear();
            max_hack.push_back(i);
        } else if(max_connect == connect){
            max_hack.push_back(i);
        }
    }

    sort(max_hack.begin(),max_hack.end());
    for(auto it = max_hack.begin();it!=max_hack.end();it++){
        cout << *it << ' ';
    }    
    return 0;
}