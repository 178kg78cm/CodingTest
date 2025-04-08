#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    map<int,int> cards_counter;
    vector<int> cards(N);
    for(int i=0;i<N;i++){
        cin >> cards[i];
        cards_counter[cards[i]]++;
    }
    sort(cards.begin(),cards.end());
    int M, num;
    cin >> M;
    vector<int> counter(M,0);
    for(int i=0;i<M;i++){
        cin >> num;
        int left = 0, right = N - 1;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(cards[mid]==num){
                counter[i] = cards_counter[num];
                break;
            }else if(cards[mid]<num){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }

    for(int i=0;i<M;i++){
        cout << counter[i] << ' ';
    }
}