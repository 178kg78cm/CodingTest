#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    
    vector<int> distance(n + 1, -1);  // 각 도시의 최단 거리를 저장하는 벡터
    vector<vector<int>> graph(n + 1); // 입력된 도시 수 만큼의 크기를 가진 그래프 벡터
    queue<int> q;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    // x에서 최단 거리가 k인 모든 도시 출력, 없으면 -1
    q.push(x);
    distance[x] = 0;

    vector<int> list;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if(distance[node]>k)break;
        for (auto neighbor : graph[node]) {
            if (distance[neighbor] == -1) {  
                distance[neighbor] = distance[node] + 1;
                if(distance[neighbor]==k) list.push_back(neighbor);
                q.push(neighbor);
            }
        }
    }


    if (list.empty()) {
        cout << "-1\n";
    } else {
        sort(list.begin(),list.end());
        for (int city : list) {
            cout << city << "\n";
        }
    }
    
    return 0;
}
