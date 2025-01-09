#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> score(2,0);
    int T0 = 0, T1 = 0;
    int T = 0, cur_T = 0;

    while(n--){
        int team;
        int m, s;
        scanf("%d %d:%d", &team, &m, &s);
        cur_T = m*60 + s;
        if(score[0]>score[1]){ T0+=cur_T - T; }
        else if(score[0]<score[1]){ T1+=cur_T - T; }
        score[team-1]++;
        T = cur_T;
    }
    if(score[0]>score[1]){ T0+=2880 - cur_T; }
    else if(score[0]<score[1]){ T1+=2880 - cur_T; }

    printf("%02d:%02d\n",T0/60,T0%60);
    printf("%02d:%02d\n",T1/60,T1%60);

    return 0;
}