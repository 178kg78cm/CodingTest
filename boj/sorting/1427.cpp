#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    sort(s.begin(), s.end(), greater<>());  // 문자열 자체를 정렬

    cout << s;  // 바로 출력
}
