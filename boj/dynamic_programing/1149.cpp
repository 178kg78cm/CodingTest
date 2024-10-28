#include <iostream>
#include <algorithm>
using namespace std;

int cost[1001][3];  // 각 집을 칠할 비용 저장

int main() {
    int n;
    cin >> n;

    // 각 집을 칠할 비용 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // 동적 계획법을 통해 각 집을 칠하는 최소 비용 계산
    for (int i = 1; i < n; i++) {
        cost[i][0] += min(cost[i-1][1], cost[i-1][2]);  // 빨간색으로 칠할 경우
        cost[i][1] += min(cost[i-1][0], cost[i-1][2]);  // 초록색으로 칠할 경우
        cost[i][2] += min(cost[i-1][0], cost[i-1][1]);  // 파란색으로 칠할 경우
    }

    // 마지막 집에서 세 가지 색 중 최소 비용 선택
    cout << min({cost[n-1][0], cost[n-1][1], cost[n-1][2]}) << '\n';

    return 0;
}
