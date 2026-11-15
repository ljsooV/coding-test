#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct file_info
{
    string ori;
    string head;
    string num;
    string tail;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<file_info> infos(files.size());
    for(size_t i = 0; i < files.size(); i++)
    {
        infos[i].ori = files[i];
        string s = files[i];
        
        bool is_num_part = false;
        bool is_tail_part = false;
        
        string t = "";
        for(size_t j = 0; j < s.length(); j++)
        {
            if(isalpha(s[j]))
            {
                if (is_num_part)
                {
                    infos[i].tail += tolower(s[j]);
                    
                    is_tail_part = true;
                }
                else
                {
                    infos[i].head += tolower(s[j]);
                }
            }
            else if (s[j] >= '0' && s[j] <= '9')
            {
                if (is_tail_part)
                {
                    infos[i].tail += s[j];
                }
                else
                {
                    infos[i].num += s[j];
                    
                    is_num_part = true;
                }
            }
            else
            {
                if (is_num_part)
                {
                    infos[i].tail += tolower(s[j]);
                    
                    is_tail_part = true;
                }
                else
                {
                    infos[i].head += tolower(s[j]);
                }
            }
        }
    }
    
   stable_sort(infos.begin(), infos.end(),
    [](const file_info& a, const file_info& b)
    {
        if (a.head != b.head)
            return a.head < b.head;

        return stoi(a.num) < stoi(b.num);
    });
    
    for (const auto& info : infos)
    {
        answer.push_back(info.ori);
    }
    
    return answer;
}