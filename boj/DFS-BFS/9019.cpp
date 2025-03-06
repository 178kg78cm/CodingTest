#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
int main(){
    int t;
    cin >> t;

    while(t--){
        queue<int> nq;
        int n, n2;
        cin >> n >> n2;
        int digits = 1000;
        int D, S, L, R;
        vector<int> visit(10000,-1);
        char command[10000] = {0,};
        nq.push(n);
        
        int r;
        visit[n]=n;
        while(!nq.empty()){
            r = nq.front();
            nq.pop();
                
            D = (2 * r) % 10000;
            if(visit[D] == -1){
                command[D] = 'D';
                visit[D] = r;
                if(D==n2)
                    break;
                nq.push(D);
            }

            S = (r - 1);    
            if (S == -1) S = 9999;
            if(visit[S] == -1){
                command[S] = 'S';
                visit[S] = r;
                if(S==n2)
                    break;
                nq.push(S);
            }
            
            L = ((r * 10) % 10000) + (int)(r/1000);
            if(visit[L] == -1){
                command[L] = 'L';
                visit[L] = r;
                if(L==n2)
                    break;
                nq.push(L);
            }

            R = (r%10) * 1000 + r / 10;
            if(visit[R] == -1){
                command[R] = 'R';
                visit[R] = r;
                if(R==n2)
                    break;
                nq.push(R);
            }
        }
        
        vector<char> answer;
        for(int k = n2;k!=n;k=visit[k]){
            answer.push_back(command[k]);
        }
        for(int i=answer.size()-1;i>=0; i--)
            cout << answer[i];
        cout << '\n';
    }

}