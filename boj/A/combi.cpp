#include <iostream>
#include <vector>
using namespace std;
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

int main() {
    int n = 5; // 전체 요소의 개수
    int k = 3; // 선택할 개수

    combination_indices(0, n, k);

    // 결과 출력
    for (const auto& comb : result) {
        for (int idx : comb) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
