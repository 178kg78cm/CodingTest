#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n;
    vector<int> deq(n);
    for(int i=0;i<n;i++){
        cin >> k;
        deq[i] = k;
    }
    sort(deq.begin(),deq.end());

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> k;
        int left=0, right=n-1;
        while(left <= right){
            int mid = (right + left) / 2;
            if(k==deq[mid]){
                cout << "1 ";
                break;
            }else if(k>deq[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if(left > right ){
            cout << "0 ";
        }
    }

    return 0;
}