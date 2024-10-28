#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // 좌표 압축을 위한 정렬 및 중복 제거
    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end()); // erarse를 사용해서 중복을 제거 가능 (또는 unique)

    for (int i = 0; i < n; i++) {
        cout << lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin() << " "; // 이 라인이 핵심 이진탐색으로 상대 위치를 찾을 수 있어야 함.
    }

    return 0;
}
