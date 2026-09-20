#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<int> st;
    
    int n = prices.size();
    for(size_t i = 0; i < n; i++)
    {
        while(st.size() && prices[st.back()] > prices[i])
        {
            int j = st.back();
            st.pop_back();
            answer[j] = i - j;
        }
        
        st.push_back(i);
    }
    
    while(st.size())
    {
        int j = st.back();
        st.pop_back();
        answer[j] = n - 1 - j;
    }
    
    return answer;
}