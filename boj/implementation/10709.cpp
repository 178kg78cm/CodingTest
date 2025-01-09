#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> input(h,vector<char>(w,0));
    vector<vector<int>> output(h,vector<int>(w,-1));

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> input[i][j];
        }
    }


    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(input[i][j] == 'c'){
                output[i][j] = 0;
            } else if(input[i][j] == '.'){
                if(j>0){
                    if(output[i][j-1]!= -1){
                        output[i][j] = output[i][j-1] + 1;
                    } 
                } 
            } 
            cout << output[i][j] << ' ';
        }
        cout << '\n';
    }
}