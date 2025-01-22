#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> home, chicken;
vector<vector<int>> dist;
int n, m, total = 1e9;

// 조합 생성과 동시에 처리
void combination_indices(int start, int k, vector<int>& temp) {
    if (temp.size() == k) {
        int comb_total = 0;
        for (int i = 0; i < home.size(); i++) {
            int min_dist = 1e9;
            for (int idx : temp) {
                min_dist = min(min_dist, dist[i][idx]);
            }
            comb_total += min_dist;
            if (comb_total >= total) break; // 조기 종료
        }
        total = min(total, comb_total);
        return;
    }

    for (int i = start; i < chicken.size(); i++) {
        temp.push_back(i);
        combination_indices(i + 1, k, temp);
        temp.pop_back();
    }
}

int main() {
    cin >> n >> m;
    int mmap[50][50];

    // 입력 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 1) home.push_back({i, j});
            else if (mmap[i][j] == 2) chicken.push_back({i, j});
        }
    }

    // 집-닭집 거리 계산
    dist.resize(home.size(), vector<int>(chicken.size()));
    for (int i = 0; i < home.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            dist[i][j] = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
        }
    }

    // 조합 생성 및 최소 거리 계산
    vector<int> temp;
    combination_indices(0, m, temp);

    cout << total;
    return 0;
}
