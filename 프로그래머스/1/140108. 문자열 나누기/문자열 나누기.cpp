#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    while(s.length())
    {
        string same_c = "";
        string diff_c = "";
        string splite_c = "";
        bool is_same = false;
        
        for(size_t i = 0; i < s.length(); i++)
        {
            if(0 == i)
            {
                same_c += s[i];
                splite_c += s[i];
                
                continue;
            }
            
            if(s[i] == same_c[0])
            {
                same_c += s[i];
                splite_c += s[i];
            }
            else
            {
                diff_c += s[i];
                splite_c += s[i];
            }
            
            if(same_c.length() == diff_c.length())
            {
                answer++;
                
                s = s.substr(i + 1);
                
                is_same = true;
                
                break;
            }
            
        }
        
        if(false == is_same)
        {
            answer++;
            
            break;
        }
    }
    return answer;
}