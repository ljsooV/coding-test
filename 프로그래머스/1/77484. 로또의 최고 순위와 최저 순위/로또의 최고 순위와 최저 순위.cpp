#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int best_cnt = 7, worst_cnt = 7;
    
    for(size_t i = 0; i < lottos.size(); i++)
    {
        for(size_t j = 0; j < win_nums.size(); j++)
        {
            if(lottos[i] == win_nums[j])
            {
                best_cnt--;
                worst_cnt--;
            }
        }
        
        if (lottos[i] == 0)
        {
            best_cnt--;
        }
    }
    
    if (worst_cnt == 7)
    {
        worst_cnt = 6;
    }
    if (best_cnt == 7)
    {
        best_cnt = 6;
    }
    
    answer.push_back(best_cnt);
    answer.push_back(worst_cnt);
    
    return answer;
}