#include <iostream>

using namespace std;

int main(){
    int m, n, h;
    int cnt=0;
    int box[100][100][100];
    cin >> m >> n >> h;
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++){
                cin >> box[k][j][i];
                if(box[k][j][i]==0) cnt++;
            }

    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++){
                if(box[k][j][i]==1){
                    
                }
            }

    return 0;
}