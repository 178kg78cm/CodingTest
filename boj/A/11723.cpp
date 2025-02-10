#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int m, input;
    bool mset[21] = {0,};
    string cmd;

    cin >> m;
    while(m--){
        cin >> cmd;
        if(cmd=="all")fill(mset,mset+21,1);
        else if(cmd=="empty")fill(mset,mset+21,0);
        else{
            cin >> input;
            if(cmd == "add")mset[input]=1;
            else if(cmd=="check")cout << mset[input] << '\n';
            else if(cmd=="toggle")mset[input]=!mset[input];
            else if(cmd=="remove")mset[input]=0;
        }
    }
    return 0;
}


/*
#include <iostream>

int main() {
    int bitset = 0;
    int count;
    int value;
    std::string command;
    
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> count;
    while (count--) {
        std::cin >> command;
        if (command == "empty")
            bitset = 0;
        else if (command == "all")
            bitset = 0x000fffff;
        else {
            std::cin >> value;
            value--;
            if (command == "add")
                bitset |= 1 << value;
            else if (command == "remove")
                bitset &= ~(1 << value);
            else if (command == "check")
                bitset & (1 << value) ? std::cout << "1\n" : std::cout << "0\n";
            else 
                bitset ^= 1 << value;
        }
    }
}
*/