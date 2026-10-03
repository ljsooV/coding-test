#include <vector>
#include <queue>

using namespace std;

struct info {
    int val;
    int cnt;
};

int solution(int x, int y, int n) {
    vector<bool> visited(y + 1, false);
    queue<info> q;

    q.push({x, 0});
    visited[x] = true;

    while (q.size()) 
    {
        info cur = q.front();
        q.pop();

        if (cur.val == y) 
        {
            return cur.cnt;
        }

        int next_vals[] = 
        {
            cur.val + n,
            cur.val * 2,
            cur.val * 3
        };

        for (int next : next_vals) 
        {
            if (next <= y && false == visited[next]) 
            {
                visited[next] = true;
                q.push({next, cur.cnt + 1});
            }
        }
    }

    return -1;
}