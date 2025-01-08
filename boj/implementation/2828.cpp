#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k; // 게임 넓이 n, 바구니 크기 m, 총 사과 갯수 k

    cin >> n >> m;
    cin >> k;
    vector<int> v;
    for(int i=0;i<k;i++){
        int pos;
        cin >> pos;
        v.push_back(pos);
    }
    m--;
    int pos = 1;
    int mov = 0, total_mov=0;
    for(int i=0;i<k;i++){
        if(pos+m >= v[i] && pos<=v[i])
            continue;
        
        if(pos>v[i]){ // 왼쪽으로 이동
            mov = pos-v[i];
            pos -= mov;
            total_mov+= mov;
        }else if(pos+m < v[i]){ // 오른쪽으로 이동
            mov = v[i]-(pos+m);
            pos += mov;
            total_mov+= mov;
        }
    }

    cout << total_mov;
}