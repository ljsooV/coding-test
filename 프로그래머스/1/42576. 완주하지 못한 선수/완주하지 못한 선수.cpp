#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_multimap<string, int> m;
    
    for(size_t i = 0; i < participant.size(); i++)
    {
        m.emplace(participant[i], i);
    }
    
    for(size_t i = 0; i < completion.size(); i++)
    {
        unordered_multimap<string, int>::iterator it = m.find(completion[i]);
        if(it != m.end())
        {
            m.erase(it);
        }
    }
    
    string answer = "";
    for(auto it = m.begin(); it != m.end(); it++)
    {
        answer = it->first;
    }
    
    return answer;
}