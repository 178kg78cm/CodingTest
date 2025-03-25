#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, s1, s2;
int n;

char toggle(char c) {
    return (c == '0') ? '1' : '0';
}

int flip(int k){
    int answer = 0;
    for(int i = k; i < n; i++){
        if(s1[i - 1] != s2[i - 1]){
            if(i - 1 >= 0) s1[i - 1] = toggle(s1[i - 1]);
            s1[i] = toggle(s1[i]);
            if(i + 1 < n) s1[i + 1] = toggle(s1[i + 1]);
            answer++;
        }
    }

    if(s1 == s2) return answer;
    else return -1;
}

int main(){
    cin >> n >> s >> s2;

    s1 = s;
    int answer1 = flip(1); // 첫 스위치를 누르지 않은 경우

    s1 = s;
    if(n >= 1) s1[0] = toggle(s1[0]);
    if(n >= 2) s1[1] = toggle(s1[1]);
    int answer2 = flip(1); // 첫 스위치를 누른 경우
    if(answer2 != -1) answer2 += 1;

    if(answer1 == -1 && answer2 == -1)
        cout << -1;
    else if(answer1 == -1)
        cout << answer2;
    else if(answer2 == -1)
        cout << answer1;
    else
        cout << min(answer1, answer2);

    return 0;
}
    