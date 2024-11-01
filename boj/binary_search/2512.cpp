#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    long long budget_plan[100001];
    long long require=0;
    for(int i=0;i<n;i++){
        cin >> budget_plan[i];
        require+=budget_plan[i]; // 요구 예산 총액
    }
    int total;
    cin >> total; // 전체 예산
    long long max_budget=*max_element(budget_plan, budget_plan+n);
    long long left=1, right=max_budget;

    if(require<=total) cout << max_budget; // 필요만큼 또는 많은 예산안 존재.
    else{// 필요보다 예산이 적을 때
        while(right>=left){ 
            require=0;
            long long mid=(right+left)/2;
            for(int i=0;i<n;i++)
                require+= min(budget_plan[i],mid); // 핵심 : 만족하는 예산 찾기
            if(require>total){
                right=mid-1;
            } else{
                max_budget = mid;
                left=mid+1;
            }
        }

        cout << max_budget;
    }
    return 0;
}