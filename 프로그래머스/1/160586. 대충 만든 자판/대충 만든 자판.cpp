#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    
    for(size_t i = 0; i < targets.size(); i++)
    {
        int count = 0;
        bool is_possible = true;
        for(size_t j = 0; j < targets[i].length(); j++)
        {
            int press_count = 101;           
            for(size_t k = 0; k < keymap.size(); k++)
            {
                for(size_t l = 0; l < keymap[k].length(); l++)
                {
                    if(targets[i][j] == keymap[k][l])
                    {
                        if(l < press_count)
                        {
                            press_count = l + 1;
                        }
                    }
                }
            }
            
            if(101 == press_count)
            {
                is_possible = false;
                
                break;
            }
            else
            {
                count += press_count;
            }
        }
        
        if (is_possible)
        {
            answer[i] = count;
        }
        else
        {
            answer[i] = -1;
        }
    }
    
    return answer;
}