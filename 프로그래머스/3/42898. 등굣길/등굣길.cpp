#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<bool>> is_puddle(n + 1, (vector<bool>(m + 1, false)));
    for(vector<int> t : puddles)
    {
        if (t[0] < 1 || t[0] > m || t[1] < 1 || t[1] > n)
        {
            continue;
        }
            
        is_puddle[t[1]][t[0]] = true;
    }
    
    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
    v[1][1] = 1;
    
    for(size_t i = 1; i <= n; i++)
    {
        for(size_t j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1)
            {
                continue;
            }
            
            if(is_puddle[i][j])
            {
                continue;
            }

            v[i][j] = (v[i - 1][j] + v[i][j - 1]) % 1000000007;
        }
    }
    
    return v[n][m];
}