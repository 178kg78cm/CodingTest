#include <iostream>
using namespace std;
int main(){
    int n;
    int ingred[16][5];
    int essen[4];
    cin >> n;
    cin >> essen[0] >> essen[1] >> essen[2] >> essen[3];
    for(int i=1;i<=n;i++){
        cin >> ingred[i][0] >> ingred[i][1] >> ingred[i][2] >> ingred[i][3] >> ingred[i][4];
    }
    int min_cost = 1e9;
    int min_index = 0;
    for(int i=1;i<((1<<(n+1))-1);i++){
        int sum_essen[4] = {0,};
        int sum_cost = 0;
        for(int j=1;j<=n;j++){
            if((i>>(j-1))&1){
                for(int k=0;k<4;k++){
                    sum_essen[k]+=ingred[j][k];
                }
                sum_cost += ingred[j][4];
            }
        }
        int count = 0;
        for(int j=0;j<4;j++){
            if(essen[j]<=sum_essen[j]) count++;
        }
        if(count==4) {
            if(min_cost>sum_cost){
                min_cost = sum_cost;
                min_index = i;
            } else if(min_cost==sum_cost){
                int bit_check = 0;
                while(1){
                    int mi = min_index >> bit_check;
                    int ti = i >> bit_check;
                    
                    if((mi&-mi) > (ti & -ti)) {
                        min_index = i;
                        break;
                    }
                    bit_check++;
                }
            }
        }
    }

    cout << min_cost << '\n';

    for(int i=1;min_index;i++){
        if(min_index & 1) cout << i << ' ';
        min_index = min_index >> 1;
    }
    return 0;
}