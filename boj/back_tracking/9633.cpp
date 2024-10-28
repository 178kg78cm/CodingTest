#include <iostream>

using namespace std;
int row, result = 0;
bool col[15] = {0,};
bool diagL[30] = {0,}, diagR[30] = {0,};
void queen(int n){
    if(n==row){
        result++;
        return;
    }
    for(int i=0;i<row;i++){
        if(!col[i]&&!diagL[n-i+row-1]&&!diagR[n+i]){
            col[i] = diagL[n-i+row-1] = diagR[n+i] = true;
            queen(n+1);
            col[i] = diagL[n-i+row-1] = diagR[n+i] = false;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> row;
    queen(0);
    cout << result;

    return 0;
}