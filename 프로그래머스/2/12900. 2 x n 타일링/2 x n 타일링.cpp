#include <string>
#include <vector>

using namespace std;

vector<int> is_visited(60001, 0);

long long fibo(int n)
{
    
    if (n <= 0)
    {
        return 0;
    }
    else if (is_visited[n] != 0)
    {
        return is_visited[n];
    }
    else if(1 == n || 2 == n)
    {
        is_visited[n] = n;
        
        return n;
    }
    
    is_visited[n] = (fibo(n-2) + fibo(n-1)) % 1000000007;
    
    return is_visited[n];
}

long long solution(int n) {

    return fibo(n);
}