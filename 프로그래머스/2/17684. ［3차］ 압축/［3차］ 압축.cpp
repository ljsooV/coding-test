#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    vector<string> dict;
    for (int i = 65; i <= 90; i++)
    {
        dict.emplace_back(1, static_cast<char>(i));
    }

    for (size_t i = 0; i < msg.size(); i++)
    {
        string s(1, msg[i]);
        int idx = -1;
        for (size_t k = 0; k < dict.size(); k++)
        {
            if (dict[k] == s)
            {
                idx = k + 1;

                break;
            }
        }

        for (size_t j = i + 1; j < msg.size(); j++)
        {
            s += msg[j];
            bool is_find = false;

            for (size_t k = 0; k < dict.size(); k++)
            {
                if (dict[k] == s)
                {
                    idx = k + 1;
                    i = j;

                    is_find = true;

                    break;
                }
            }

            if (false == is_find)
            {
                break;
            }
        }

        dict.push_back(s);
        answer.push_back(idx);

    }

    return answer;
}