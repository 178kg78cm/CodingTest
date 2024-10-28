#include <iostream>
using namespace std;
int main(){
    int arr[100][100] = {0,};
    int n,m,x;
    cin >> n >> m;

    for(int k=0;k<2;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> x;
                arr[i][j] = arr[i][j] + x;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}