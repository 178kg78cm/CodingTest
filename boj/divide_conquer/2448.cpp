#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> v;
//   *                        
//  * *                       
// *****
void triangle(int i,int j){
    v[i][j]='*';
    v[i+1][j-1]='*';
    v[i+1][j+1]='*';
    v[i+2][j-2]='*';
    v[i+2][j-1]='*';
    v[i+2][j]='*';
    v[i+2][j+1]='*';
    v[i+2][j+2]='*';
}
void tritri(int i, int j){
    triangle(i,j);
    triangle(i+3,j-3);
    triangle(i+3,j+3);
}
int main(){
    int N;
    cin >> N;
    v.resize(N*2+1,string(N*2+1,' '));
    for(int n=1;n!=N;n*=2){

    }
}