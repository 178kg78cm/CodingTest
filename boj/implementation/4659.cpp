#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int alphabet[26] = {0,};
    int gather[5] = {0,4,8,14,20};
    while(cin >> s){
        if(s=="end") break;
        bool vaild = true;
        int gather_count = 0;
        bool gather_check = false;
        int cons_count = 0;
        for(int i=0;i<s.length();i++){
            int target = s[i]-'a';
            auto it = find(begin(gather), end(gather),target);
            if(it != end(gather)){
                gather_count++;
                gather_check = true;
                cons_count=0;
            }else{
                gather_count=0;
                cons_count++;
            }

            if(i>0) {
                if(s[i-1]==s[i]){
                    if(!(target==4 || target==14)){
                        vaild = false;
                    }
                }
            }
            if(cons_count==3||gather_count==3) vaild = false;
            if(!vaild) break;
        }
        if(!gather_check) vaild = false;
        if(vaild) 
            cout << "<" << s << "> is acceptable.\n";
        else
            cout << "<" << s << "> is not acceptable.\n";
    }

}