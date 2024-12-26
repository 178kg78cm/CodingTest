#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> poketmon(nums.begin(), nums.end()); // 중복 제거를 위해 unordered_set 사용

    int answer = min(poketmon.size(), nums.size() / 2); // 최대 고유 포켓몬 수 계산
    return answer;
}
