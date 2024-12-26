#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> gom;  // 팬클럽이 있는 노드를 표시
int n, m;
bool check=false; // 팬 없이 끝까지 가면 true
void dfs(int node) {
    if(gom[node]) return;
    else if (graph[node].empty()) check = true;
    for(auto target : graph[node]){
        dfs(target);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph.resize(n + 1);
    gom.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int S;
    cin >> S;
    for (int i = 0; i < S; i++) {
        int s;
        cin >> s;
        gom[s]=true;
    }

    // 1번 노드에서 DFS 시작
    dfs(1);

    // 결과 출력
    if (check) {
        cout << "yes\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}
