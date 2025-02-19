#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string line, bomb;

    cin >> line >> bomb;

    // int idx, idxe;
    // while(s.find(bomb) != string::npos){
    //     idx  = s.find(bomb);
    //     idxe = idx+bomb.length();
    //     s.erase(s.begin() + idx,s.begin() + idxe);
    // }
    
    
    // if(s.empty())
    //     cout << "FRULA";
    // else
    //     cout << s;

    stack<char> s;
    for(int i=0;i<line.length();i++){
        s.push(line[i]);        
        if(bomb[bomb.length()-1]==s.top()){
            bool valid = 1;
            for(int j=0;j<bomb.length();j++){
                if(s[s.size()-j]!=bomb[j]){
                    valid = 0;
                } 
            }
            if(valid){
                for(int j=0;j<bomb.length();j++) s.po
            }
        }
    }
    while(!s.empty()){
        if(s.)
    }

    return 0;
}