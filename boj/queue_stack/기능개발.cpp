#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        int date = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
        q.push(date);
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int cnt = 1;

        while (!q.empty() && q.front() <= current) {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }

    return answer;
}
