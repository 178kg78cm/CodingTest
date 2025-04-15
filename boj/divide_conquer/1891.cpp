#include <iostream>
#include <string>
using namespace std;
string answer = "";
long long d;
string N;
long long dx, dy, range;

void qurd(long long y, long long x, long long basey, long long basex, long long dim){
    if(dim==-1){
        return;
    }
    long long mid = 1LL << dim;
    if(y<basey+mid){
        if(x>=basex+mid){
            cout << 1;
            qurd(y,x,basey,basex+mid,dim-1);    
        }else{
            cout << 2;
            qurd(y,x,basey,basex,dim-1);    
        }
    }else{
        if(x<basex+mid){
            cout << 3;
            qurd(y,x,basey+mid,basex,dim-1);    
        }else{
            cout << 4;
            qurd(y,x,basey+mid,basex+mid,dim-1);    
        }
    }
}

void cord(long long y, long long x, long long dim){
    if(dim==-1){
        if(y-dy>=range || x+dx>=range || y-dy<0 || x+dx<0){
            cout << -1;
            return;
        }
        qurd(y-dy,x+dx,0,0,d);
        return;
    }   
    long long mid = 1LL << dim; 
    if(N[d-dim]=='1'){
        cord(y,x+mid,dim-1);
    }
    else if(N[d-dim]=='2'){
        cord(y,x,dim-1);
    }
    else if(N[d-dim]=='3'){
        cord(y+mid,x,dim-1);
    }
    else{
        cord(y+mid,x+mid,dim-1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> N;
    cin >> dx >> dy;
    range = 1LL << d;
    d--;
    cord(0,0,d);
}

// 이 문제는 long long의 범위를 정확하게 파악을 했어야함. 진작에 string을 떠올렸어야함
// 2의 제곱꼴을 보자마자 bit shift 연산을 떠올려야함
