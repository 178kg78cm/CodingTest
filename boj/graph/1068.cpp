#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v[n];
    int head=-1;
    for(int i=0;i<n;i++){
        int parent;
        cin >> parent;
        if(parent==-1){
            head = i;
        }else{
            v[parent].push_back(i);
        }
    }
    int xnode, leaf= 0;
    cin >> xnode;
    v[xnode].clear();

    queue<int> q;
    q.push(head);
    if(head==xnode) {
        cout << 0;
        return 0;
    }
    while(!q.empty()){
        int curhead = q.front();
        q.pop();
        if(v[curhead].empty()){
            leaf++;
        }else{
            for(auto child : v[curhead]){
                if(child!=xnode)
                    q.push(child);
                else if(v[curhead].size()==1){
                    leaf++;
                }
            }
        }
    }
    
    cout << leaf;
    return 0;
}