#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    int curr_num = 1;
    stack<int> st;
    
    for(size_t i = 0; i < order.size(); i++)
    {
        if(st.size())
        {
            if (order[i] == st.top())
            {                
                answer++;
                st.pop();
                
                continue;
            }
        }
        
        bool is_find = false;
        while(curr_num <= order.size())
        {
            if(curr_num == order[i])
            {
                answer++;
                curr_num++;
                
                is_find = true;
                
                break;
            }
            else
            {
                st.push(curr_num);                
                curr_num++;
            }
        }
        
        if(false == is_find)
        {
            break;
        }
    }
    
    return answer;
}