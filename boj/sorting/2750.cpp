#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;

    int arr[1001];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        cout << arr[i] << "\n";
    }

    return 0;
}
