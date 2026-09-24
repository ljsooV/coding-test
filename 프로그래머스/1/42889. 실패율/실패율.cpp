#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct f_rate
{
    float uncleared_p;
    float reach_p;
    float rate;
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    map<int, f_rate> m;
    
    sort(stages.begin(), stages.end());
    
    int curr_stage = stages[0];
    for(size_t i = 0; i < stages.size(); i++)
    {
        m[stages[i]].uncleared_p++;
        m[stages[i]].reach_p++;
        
        if(curr_stage != stages[i])
        {
            int n_stage = stages.size() - i;
            m[curr_stage].reach_p += n_stage;
            
            curr_stage = stages[i];
        }
    }
    
    cout << m.size() << endl;
    
    for(map<int, f_rate>::iterator it = m.begin(); it != m.end(); it++)
    {
        it->second.rate = it->second.uncleared_p / it->second.reach_p;
    }
    
    map<int, float> r;
    for(size_t i = 1; i <= N; i++)
    {
        if(m.find(i) != m.end())
        {
            r[i] = m[i].rate;
        }
        else
        {
            r[i] = 0;
        }
    }
    
    vector<pair<float, int>> temp;

    for (const auto& p : r) {
        temp.push_back({-p.second, p.first});
    }

    sort(temp.begin(), temp.end());

    for (const auto& p : temp) {
        answer.push_back(p.second);
    }
    
    
    return answer;
}