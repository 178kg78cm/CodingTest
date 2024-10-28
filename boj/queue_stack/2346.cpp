#include <iostream>
#include <deque>
#include <vector> // 또는 utility
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,cnt=1;
    deque<pair<int,int>> d;
    cin >> n;
    for(int i=1;i<=n;i++){
        pair<int, int> b;
        cin >> k;
        b.first = i;
        b.second = k;

        d.push_back(b);
    }

    while(n--){
        cout << d.front().first << ' ';
        k=d.front().second;
        d.pop_front();
        if(k<0){
            while(k++){
                d.push_front(d.back());
                d.pop_back();
            }
        }
        else{
            k--;
            while(k--){
                d.push_back(d.front());
                d.pop_front();
            }
        }
    }

    return 0;
}
// circler queue 개념 확인 필요
