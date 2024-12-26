#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    long long m;

    cin >> n >> m;
    vector<long long> wood_list(n);

    for (int i = 0; i < n; i++) {
        cin >> wood_list[i];
    }

    long long left = 0, right = *max_element(wood_list.begin(), wood_list.end());
    long long result = 0;

    while (left <= right) {
        long long total = 0;
        long long mid = (left + right) / 2;

        for (int i = 0; i < n; i++) {
            if (wood_list[i] > mid) {
                total += wood_list[i] - mid;
            }
        }

        if (total >= m) {  
            result = mid;  
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result;
    return 0;
}
