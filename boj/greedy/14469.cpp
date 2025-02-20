#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int at, t;
    for(int i=0;i<n;i++){
        cin >> at >> t;
        v[i] = make_pair(at,t);
    }
    sort(v.begin(),v.end());
    int total = 0;
    for(int i=1;i<n;i++){
        int a = v[i-1].first+v[i-1].second;
        int b = v[i].first+v[i].second;

        if(a<v[i].first){
            total = b;
        }else if(b>a){
            total += (b-a);
        }else{
            
        }
    }

    return 0;
}