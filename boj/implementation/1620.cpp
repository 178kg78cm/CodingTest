#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    unordered_map<int,string> dic;
    unordered_map<string,int> dic2;

    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        dic.insert(make_pair(i+1,name));
        dic2.insert(make_pair(name,i+1));
    }

    while(m--){
        string s;
        cin >> s;
        if('0'<=s[0]&&'9'>=s[0]){
            cout << dic.find(stoi(s))->second << '\n';
        }
        else{
            cout << dic2.find(s)->second << '\n';    
        }
    }

    return 0;
}

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m;
//     cin >> n >> m;

//     vector<string> dic(n);
//     for(int i=0;i<n;i++){
//         cin >> dic[i];
//     }

//     while(m--){
//         string s;
//         cin >> s;
//         if('0'<s[0]&&'9'>s[0]){
//             cout << dic[stoi(s)-1] << '\n';
//         }else{
//             for(int i=0;i<n;i++){
//                 if(s==dic[i]){
//                     cout << i+1 << '\n';
//                     break;
//                 }
//             }
//         }
//     }

//     return 0;
// }