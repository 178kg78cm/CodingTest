#include <iostream>
#include <string>

using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);


    int alphabet[26] = {0,};
    int n;
    bool answer = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        alphabet[int(name[0]-'a')]++;  
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]>= 5){
            cout << char(i+'a');
            answer = 1;
        }
    }
    if(!answer) cout << "PREDAJA";
    return 0;
}