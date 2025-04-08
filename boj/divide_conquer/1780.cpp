#include <iostream>
#define MAX 9*9*9*3
using namespace std;
int answer[3] = {0,};
int board[MAX][MAX];
void check(int y, int x, int n){
    int base = board[y][x];
    if(n==1){
        answer[base + 1]++;
        return;
    }
    bool valid = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(base!=board[y+i][x+j]){
                valid = 0;
            }
        }
    }
    if(valid){
        answer[base+1]++;
    }
    else{
        int nn = n/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                check(y+i*nn,x+j*nn,nn);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }

    check(0,0,N);

    for(int i=0;i<3;i++){
        cout << answer[i] << '\n';
    }
}