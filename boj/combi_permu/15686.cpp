#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;

vector<vector<int>> result; // 조합 결과 (인덱스 저장)
vector<int> temp; // 현재 선택된 인덱스 저장
void combination_indices(int start, int n, int k) {
    if (temp.size() == k) { // k개의 인덱스를 선택한 경우
        result.push_back(temp);
        return;
    }

    for (int i = start; i < n; i++) {
        temp.push_back(i); // 인덱스 선택
        combination_indices(i + 1, n, k); // 다음 인덱스 선택
        temp.pop_back(); // 백트래킹
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int mmap[50][50];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mmap[i][j];
            if(mmap[i][j]==1) home.push_back({i,j});
            else if(mmap[i][j]==2) chicken.push_back({i,j});
        }
    }
    combination_indices(0, chicken.size(), m);
    int total = 1e9;
    for (const auto& comb : result) {
        int comb_total = 0;
        for(int i=0;i<home.size();i++){
            int min = 1e9;
            for (int idx : comb) {
                int dist = abs(chicken[idx].first - home[i].first) + abs(chicken[idx].second - home[i].second);
                if (min > dist) min = dist;
            }
            comb_total += min;
        }
        if(total > comb_total) total = comb_total;
    }
    cout << total;
}