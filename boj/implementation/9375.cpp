#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
                                                            
    while(T--){
        int n;
        cin >> n;
        unordered_map<string, int> patt;
        while(n--){
            string name, catego;
            cin >> name >> catego;
            
            if(patt.find(catego) != patt.end()){
                patt[catego]++;
            }else{
                patt[catego] = 1;
            }
        }
        int answer = 1;
        for(auto it = patt.begin();it!=patt.end();it++){
            answer*=(it->second+1);
        }
        cout << answer-1 << "\n";
    }

    return 0;
}   