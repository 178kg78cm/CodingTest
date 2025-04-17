#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct{
    int age;
    string name;
    int id;
} Info;
bool cmp(const Info a, const Info b){
    if(a.age == b.age) return a.id < b.id;
    return a.age < b.age;
}
int main(){
    int n, id = 0;
    cin >> n;
    vector<Info> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].age >> v[i].name;
        v[i].id = id++;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        cout << v[i].age << ' ' << v[i].name << '\n';
    }
}