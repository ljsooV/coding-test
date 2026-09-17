#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_hex(int n)
{
    switch(n)
    {
        case 10:
            return 65;
        case 11:
            return 66;
        case 12:
            return 67;
        case 13:
            return 68;
        case 14:
            return 69;
        case 15:
            return 70;
    }
    
    return n;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int turn = 1;
    int cnt = 0;
    while(answer.size() < t)
    {
        string s = to_string(cnt);
        
        //cout << "cnt: " << cnt << " ";
        
        if(cnt >= n)
        {
            string decimal = "";
            int num = cnt;
            
            while (num / n != 0)
            {
                int mod = num % n;
                if (mod >= 10 && n >= 10)
                {
                    char c = get_hex(mod);
                        
                    decimal += c;
                }
                else
                {
                    decimal += to_string(num % n);
                }
                
                num /= n;
            }
            
            if (num >= 10 && n >= 10)
            {
                char c = get_hex(num);
                        
                decimal += c;
            }
            else
            {
                decimal += to_string(num);
            }
            
            reverse(decimal.begin(), decimal.end());
            s = decimal;
            
            //cout << "s: " << s;
        }
        else
        {
            if(cnt >= 10 && n >= 10)
            {
                char c = get_hex(cnt);
                
                s = c;
                
                //cout << "s: " << s;
            }
        }
        
        cout << endl;
        
        for(size_t i = 0; i < s.length(); i++)
        {
            if(turn == p)
            {
                answer.push_back(s[i]);
            }
            
            if(answer.size() >= t)
            {
                break;
            }
            
            turn++;
            
            if(turn > m)
            {
                turn = 1;
            }
        }
        
        cnt++;
    }
    
    return answer;
}