#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 0;
    int different = 0;
    char first = '\0';

    for (char c : s) 
    {
        if (same == 0 && different == 0) 
        {
            first = c;
        }

        if (c == first) 
        {
            same++;
        } 
        else 
        {
            different++;
        }

        if (same == different) 
        {
            answer++;
            same = 0;
            different = 0;
        }
    }

    if (same != 0 || different != 0) 
    {
        answer++;
    }

    return answer;
}