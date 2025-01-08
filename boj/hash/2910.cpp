#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int>& a,const pair<int,int>& b){
    if(a.second > b.second){
        return true;
    }else return false;
}
int main(){
    int n, c;
    cin >> n  >> c;

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        auto it = find_if(v.begin(), v.end(), [tmp](pair<int,int> p){
            return p.first == tmp;
        });
        if(it!=v.end()){
            v[it-v.begin()].second++;
        }    
        else{
            v.push_back({tmp,1});
        }
    }
    stable_sort(v.begin(),v.end(),
            [](const pair<int,int> a, const pair<int,int>b){
                return a.second > b.second;
            });
    for(auto it=v.begin();it!=v.end();it++){
        for(int i=0;i<it->second;i++){
            cout << it->first << " ";
        }
    }
    return 0;
}