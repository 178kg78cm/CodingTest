#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int checker() {
    int min_index = 0;

    for (int i = 1; i < v.size(); i++) {
        int mi = v[min_index];
        int ti = v[i];

        while (mi > 0 || ti > 0) {
            if ((mi & 1) != (ti & 1)) { 
                if ((ti & 1) == 1 && (mi>>1)!=0)      
                    min_index = i;
                break;
            } 
            mi >>= 1;
            ti >>= 1;
        }
        // if(mi!=0 & ti==0) min_index = i;
    }
    return min_index;
}

int main() {
    int n;
    int ingred[16][5];
    int essen[4];

    // 입력
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> essen[i];  // 필수 영양소 입력

    for (int i = 0; i < n; i++) {
        cin >> ingred[i][0] >> ingred[i][1] >> ingred[i][2] >> ingred[i][3] >> ingred[i][4];
    }

    int min_cost = 1e9;

    // 비트마스킹을 이용한 부분 집합 탐색
    for (int i = 1; i < (1 << n); i++) {
        int sum_essen[4] = {0,};
        int sum_cost = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {  // j번째 재료를 선택한 경우
                for (int k = 0; k < 4; k++) {
                    sum_essen[k] += ingred[j][k];
                }
                sum_cost += ingred[j][4];
            }
        }

        // 필수 영양소 조건을 만족하는지 확인
        bool valid = true;
        for (int j = 0; j < 4; j++) {
            if (sum_essen[j] < essen[j]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            if (sum_cost < min_cost) {
                min_cost = sum_cost;
                v.clear();
                v.push_back(i);
            } else if (sum_cost == min_cost) {
                v.push_back(i);
            }
        }
    }

    // 결과 출력
    if (v.empty()) {
        cout << -1;
    } else {
        int min_index = v[checker()];
        cout << min_cost << '\n';

        for (int i = 0; i < n; i++) {
            if (min_index & (1 << i)) cout << (i + 1) << ' ';
        }
    }

    return 0;
}
