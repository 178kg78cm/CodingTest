#include <iostream>
#include <string>

using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    char c;
    while((c=getchar())!='\n'){
        if((c<='z'&&c>='a') || (c<='Z'&&c>='A')) {
            if(c+13>'z') 
                c=(c+12-'z')+'a';
            else if(c<='Z'&&c+13>'Z')
                c=(c+12-'Z')+'A';
            else
                c=(c+13);
        } 
        cout << c;
    }
    return 0;
}