#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int checker(){
    int min_index = 0;
    for(int i=1;i<v.size();i++){
        int mi = v[min_index];
        int ti = v[i];
        while(mi==0 || ti == 0){
            if(mi==0 || ti == 0){
                if(mi!=0){
                    min_index = ti;
                }
                break;
            }
            if(!(mi & 1) && (ti & 1) ){
                min_index = i;
                break;
            }
            mi = mi >> 1;
            ti = ti >> 1;
        }
    }
    return min_index;
}
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
    for(int i=1;i<(1<<n);i++){
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
                v.clear();
                v.push_back(i);
            } else if(min_cost==sum_cost){
                v.push_back(i);
            }
        }
    }

    if(v.size()==0){
        cout << -1;
    }
    else{
        int min_index = checker();
        for(int i=1;min_index;i++){
            if(min_index & 1) cout << i << ' ';
            min_index = min_index >> 1;
        }
    }

    return 0;
}