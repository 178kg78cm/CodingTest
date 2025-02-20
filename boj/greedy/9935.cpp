#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line, bomb;

    cin >> line >> bomb;

    string s;
    for(int i=0;i<line.length();i++){
        s.push_back(line[i]);        
        if(bomb[bomb.length()-1]==s.back()){
            bool valid = 1;
            for(int j=1;j<=bomb.length();j++){
                if(s[s.length()-j]!=bomb[bomb.length()-j]){
                    valid = 0;
                    break;
                } 
            }

            if(valid){
                for(int j=0;j<bomb.length();j++) s.pop_back();
            }
        }
    }
    if(s.empty()) cout << "FRULA";
    else cout << s;

    return 0;
}