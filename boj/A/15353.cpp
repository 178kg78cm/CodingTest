#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a, b, sum;
    cin >> a >> b;
    int a_length = a.length(), b_length = b.length();
    int a_n, b_n, a_pos = 0, b_pos = 0;
    char flag = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    while(a_pos<a_length || b_pos<b_length){
        if(a_pos>=a_length) a_n = '0';
        else a_n = a[a_pos];
        if(b_pos>=b_length) b_n = '0';
        else b_n = b[b_pos];
        char temp = a_n + b_n - '0' + flag;
        if(temp>'9') {
            temp -= 10;
            flag = 1;
        }else flag = 0;
        sum.push_back(temp);
        a_pos++;
        b_pos++;     
    }if(flag) sum.push_back('1');
    reverse(sum.begin(),sum.end());
    cout << sum;
    return 0;
}