#include <iostream>
#include <string>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int n;
    cin >> n;
    getchar();
    string ps, pe;
    while((c=getchar())!='*'){
        ps.push_back(c);
    }while((c=getchar())!='\n'){
        pe.push_back(c);
    }
    while(n--){
        string s;
        cin >> s;
        if (s.length() < ps.length()+pe.length()-1) {
            cout << "NE\n";
            continue;
        }

        string ts = s.substr(0,ps.length());
        string te = s.substr(s.length()-pe.length(),s.length());
        
        if(ps==ts && pe==te) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}