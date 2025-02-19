#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    while(t--){
        vector<pair<int,int>> v(n);
        int ga, gb;
        for(int i=0;i<n;i++){
            cin >> ga >> gb;
            v[i] = make_pair(ga,gb);
        } 
        sort(v.begin(),v.end(),[](const pair<int,int> &a, const pair<int,int> &b){
            if(a.second == b.second) 
                return a.first < b.first;
            return a.second < b.second;
        });
        
        for(int i=0;i<n;i++){
            for(int )
            if(){

            }   
        }
    }
    
}