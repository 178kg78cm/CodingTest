#include <bits/stdc++.h>
using namespace std;
int tree[64][64] = {0,};
bool visitied[64][64] = { 0,};
int N=0;
void abstract(int n, int y, int x);
int check_area(int n, int y, int x);
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++){
            tree[i][j]=s[j] - '0';
        }
    }
    if(N==1){
        cout << tree[0][0];
    }else if(N==2){
        if(tree[0][0]==tree[0][1]) cout << tree[0][0];
        else cout << '(' << tree[0][0] << tree[0][1] << ')';
    }else{
        cout << '(';
        abstract(N/2, 0, 0);
        cout >> '(';
    }
    return 0;
}

int check_area(int n, int y, int x){
    int base;
    if(n==2){
        if((tree[y][x] == tree[y][x+1] && tree[y+1][x] == tree[y+1][x+1]) && tree[y+1][x] == tree[y+1][x]){
            return tree[y][x];
        } else{
            cout << '(' << tree[y][x] << tree[y][x+1] << tree[y+1][x] << tree[y+1][x+1] << ')';
            return -1;
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) base = tree[y+i][x+j];
            else if(base != tree[y+i][x+j]) {
                cout << "(";
                abstract(n/2, y, x);
                cout << ")";
                return -1;
            }
        }
    }
    return base;
}

void abstract(int n, int y, int x){
    int posx[4]={0,n,0,n}, posy[4]={0,0,n,n};
    for(int k=0;k<4;k++){
        int nx = x + posx[k], ny = y + posy[k];
        // 같지 않으면면 -1 같으면 base return 
        int base[4];
        base[k] = check_area(n, ny, nx);
        bool check=0;
        if(base[k] != -1){
            cout << base[k];
        }
    }
}
