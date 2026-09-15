#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& cnts,
         int cnt,
         const string& str,
         vector<bool>& is_visited,
         const vector<string>& words,
         const string& target)
{
    if (str == target)
    {
        cnts.push_back(cnt);
        return;
    }

    for (size_t i = 0; i < words.size(); ++i)
    {
        if (is_visited[i] || words[i].size() != str.size())
            continue;

        int diff = 0;
        for (size_t j = 0; j < str.size(); ++j)
        {
            if (str[j] != words[i][j])
                ++diff;
        }

        if (diff != 1)
            continue;

        is_visited[i] = true;
        dfs(cnts, cnt + 1, words[i], is_visited, words, target);
        is_visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<int> cnts;
    vector<bool> is_visited(words.size(), false);

    dfs(cnts, 0, begin, is_visited, words, target);

    answer = cnts.empty() ? 0 : *min_element(cnts.begin(), cnts.end());
    
    return answer;
}