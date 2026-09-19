#include <string>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    const string digits = "0123456789ABCDEF";
    string answer;
    answer.reserve(t);

    int turn = 1;

    for (int cnt = 0; answer.size() < t; ++cnt) 
    {
        string s;
        int num = cnt;

        do 
        {
            s.push_back(digits[num % n]);
            num /= n;
        } while (num > 0);

        reverse(s.begin(), s.end());

        for (char c : s) 
        {
            if (turn == p) 
            {
                answer.push_back(c);

                if (answer.size() == t) 
                {
                    return answer;
                }
            }

            turn = turn % m + 1;
        }
    }

    return answer;
}