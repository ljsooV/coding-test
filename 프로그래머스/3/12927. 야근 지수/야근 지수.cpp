#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;

    for (int work : works) 
    {
        if (work > 0) 
        {
            pq.push(work);
        }
    }

    while (n > 0 && pq.size()) 
    {
        int t = pq.top();
        pq.pop();

        --t;
        
        if (t > 0) 
        {
            pq.push(t);
        }

        --n;
    }

    while (pq.size()) 
    {
        long long t = pq.top();
        pq.pop();

        answer += t * t;
    }

    return answer;
}