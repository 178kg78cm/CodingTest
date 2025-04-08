#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> in, post;
vector<int> i_post;  

void pre(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) 
        return;

    int root = post[post_end];
    cout << root << ' ';

    int root_idx = i_post[root];  
    int left_size = root_idx - in_start;

    pre(in_start, root_idx - 1, post_start, post_start + left_size - 1);
    pre(root_idx + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    in.resize(n);
    post.resize(n);
    i_post.resize(n + 1); 

    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];

    for (int i = 0; i < n; i++) {
        i_post[in[i]] = i;
    }

    pre(0, n - 1, 0, n - 1);
    return 0;
}
