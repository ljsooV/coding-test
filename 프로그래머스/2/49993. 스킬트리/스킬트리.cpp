#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(size_t i = 0; i < skill_trees.size(); i++)
    {
        for(string::iterator it = skill_trees[i].begin(); it != skill_trees[i].end(); )
        {
            bool is_find = false;
            
            for(size_t k = 0; k < skill.length(); k++)
            {
                if(*it == skill[k])
                {
                    is_find = true;
                    
                    break;
                }
            }
            
            if(false == is_find)
            {
                it = skill_trees[i].erase(it);
            }
            else
            {
                it++;
            }
        }
        
        string s = skill;
        
        while(s.length())
        {
            if(skill_trees[i] == s)
            {
                answer++;
                
                break;
            }
            
            s.pop_back();
        }
        
        if (s.empty() && skill_trees[i].empty())
        {
            answer++;
        }
    }
    return answer;
}