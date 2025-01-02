#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int time[101] = {0,};
    cin >> a >> b >> c;
    for(int i=0;i<3;i++){
        int start, end;
        cin >> start >> end;

        for(int j=start;j<end;j++){
            time[j]++;
        }
    }
    int payment = 0;
    for(int i=1;i<=100;i++){
        if(time[i]==1){
            payment+=a;
        }else if(time[i]==2){
            payment+=b*2;
        }else if(time[i]==3){
            payment+=c*3;
        }
    }

    cout << payment;

    return 0;
}
