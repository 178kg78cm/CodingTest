#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=1;i<phone_book.size();i++){
        string front = phone_book[i-1];
        cout << phone_book[i].substr(0,front.length()-1) << endl;
        if(front == phone_book[i].substr(0,front.length()-1)){
            answer = false;
            break;
        }
    }
        
    cout << answer << endl;
    return answer;
}