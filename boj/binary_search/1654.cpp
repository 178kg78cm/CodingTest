#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int k,n;
    cin >> k >> n; // k 이미 가지고 있는 랜선, k개를 잘라서 모두 같은 n개의 랜선으로 만들어야함.

    vector<int> v;
    ll mid, right=0, left = 1;
    for(int i=0;i<k;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp); // 랜선 k개 데이터 입력 받음
        right += tmp;
    }
    right = right / n  + 1;
    while(left <= right){
        bool check = 0;
        mid = (left+right)/2;
        int num = 0;
        for(int i=0;i<k;i++){
            num+=v[i]/mid;
            if(v[i]%mid==0) check = 1;
        }
        if(num == n && check) break;
        else if(num<n){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    if(left<=right) cout << mid;
    else cout << right;
}