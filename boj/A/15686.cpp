#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;

void combination(vector<pair<int,int> v){

}
int main(){

    int n, m;
    cin >> n >> m;
    int mmap[50][50];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mmap[i][j];
            if(mmap[i][j]==1) home.push_back({i,j});
            else if(mmap[i][j]==2) chicken.push_back({i,j});
        }
    }

    for(int i=0;i<home.size();i++){
        for(int j=0;){

        }
    }
    for(int i=0;i<m;i++){
        
    }

}