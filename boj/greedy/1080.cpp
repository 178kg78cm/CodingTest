#include <iostream>
using namespace std;
char mat[51][51], cov_mat[51][51];

void conv(int y, int x){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[y+i][x+j]=='1') mat[y+i][x+j] = '0';
            else mat[y+i][x+j] = '1';
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int answer = 0;
    for(int i=0;i<n;i++){
        cin >> mat[i];
    }

    for(int i=0;i<n;i++){
        cin >> cov_mat[i];
    }
    if(n>=3 && m>=3){
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(mat[i][j]!=cov_mat[i][j]){
                    conv(i,j);
                    answer++;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=cov_mat[i][j]){
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer;
}