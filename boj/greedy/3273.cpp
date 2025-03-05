#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, target;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    } cin >> target;

    sort(v.begin(),v.end());
    int right = n-1, left = 0;
    int ans = 0, sum;
    while(left < right){
        int sum = v[left] + v[right];
        if(sum == target) {
            ans++;
            left++;
            right--;
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    cout << ans;
}