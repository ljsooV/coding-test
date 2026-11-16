#include <string>
#include <vector>

using namespace std;

struct ingre_info
{
    int ingredient;
    int loc;
};

int solution(vector<int> ingredient) {
    int answer = 0;
    
    for(size_t i = 0; i < ingredient.size(); i++)
    {
        if(ingredient[i] == 1)
        {
            if(i > 2)
            {
                if(ingredient[i-1] == 3)
                {
                    if(ingredient[i-2] == 2)
                    {
                        if(ingredient[i-3] == 1)
                        {
                            ingredient.erase(ingredient.begin() + i - 3, ingredient.begin() + i + 1);
                            
                            i -= 4;
                            
                            answer++;
                            
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}