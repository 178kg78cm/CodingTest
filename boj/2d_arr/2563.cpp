#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool area[101][101] = {0,};
    int result = 100*n;
    
    while(n--){
        int a, b;
        cin >> a >> b;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(area[i+a][j+b]) result--;
                area[i+a][j+b] = true;
            }
        }
    }

    cout << result;
    return 0;
}