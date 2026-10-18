#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> v = { "aya", "ye", "woo", "ma" };
    
    for(size_t i = 0; i < babbling.size(); i++)
    {
        string prev = "";
        bool is_prev = false;
        while(babbling[i].length())
        {
            bool is_find = false;
            for(size_t j = 0; j < v.size(); j++)
            {
                if(0 == babbling[i].find(v[j]))
                {
                    if(v[j] == prev)
                    {
                        is_prev = true;
                        
                        break;
                    }
                    else
                    {
                        babbling[i].erase(0, v[j].length());
                        
                        is_find = true;
                        prev = v[j];
                        
                        break;
                    }
                }
            }
            
            if(is_prev || false == is_find)
            {
                break;
            }
            else if (babbling[i].empty())
            {
                answer++;
            }
        }
    }
    
    return answer;
}