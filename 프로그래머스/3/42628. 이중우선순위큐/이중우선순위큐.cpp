#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

vector<int> solution(vector<string> operations) {

    multiset<int> m;
    vector<vector<string>> com;
    for(size_t i = 0; i < operations.size(); i++)
    {
        vector<string> s;
        
        for(size_t j = 0; j <operations[i].size(); j++)
        {
            if(j == 0)
            {
                string c = operations[i].substr(0, 1);
                s.push_back(c);
            }
            else if (' ' == operations[i][j])
            {
                continue;
            }
            else
            {
                string num = operations[i].substr(j);
                
                s.push_back(num);
                
                com.push_back(s);
                
                break;
            }
        }
    }
    
    for(size_t i = 0; i < com.size(); i++)
    {
        if("I" == com[i][0])
        {
            m.insert(stoi(com[i][1]));
        
        }
        else if ("D" == com[i][0])
        {
            if("1" == com[i][1])
            {
                if(m.size())
                {
                    m.erase(prev(m.end()));
                }
            }
            else if ("-1")
            {
                if(m.size())
                {
                    m.erase(m.begin());
                }
            }
        }
    }
    
    vector<int> answer;
    
    if(m.size())
    {
        answer.push_back(*m.rbegin());
        answer.push_back(*m.begin());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}