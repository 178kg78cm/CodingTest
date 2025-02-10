#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    bool valid = 1;
    int count = 0;
    while((c = getchar())!='\n'){
        count++;
        if(c=='p'){ 
            if((c = getchar())!='i'){
                valid = 0;
                break;
            }
        }
        else if(c=='k'){
            if((c = getchar())!='a'){
                valid = 0;
                break;
            }
        }else if(c=='c'){
            if((c = getchar())!='h'){
                valid = 0;
                break;
            }else{
                if((c = getchar())!='u'){
                    valid = 0;
                    break;
                }
            }
        }else{
            valid = 0;
            break;
        }
    }
    if(valid && (count>0)) cout << "YES";
    else cout << "NO";

    return 0;
}