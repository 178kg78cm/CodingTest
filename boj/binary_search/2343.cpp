#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> v(n);

    long long low = 0, high = 0, result = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        high += v[i];
        low = max(low, v[i]); // 최소값은 가장 긴 강의의 길이
    }

    while (low <= high) {
        long long mid = (low + high) / 2;
        int li = 1; // 블루레이 개수
        long long current_sum = 0;

        for (int i = 0; i < n; i++) {
            if (current_sum + v[i] > mid) {
                li++;
                current_sum = 0;
            }
            current_sum += v[i];
        }

        if (li > m) {
            low = mid + 1; // 더 큰 블루레이 크기 필요
        } else {
            result = mid; // 가능한 값 저장
            high = mid - 1; // 더 작은 블루레이 크기로 시도
        }
    }

    cout << result;
    return 0;
}
