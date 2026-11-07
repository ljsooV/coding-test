#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct score_info
{
    int score;
    int multiply;
    char option;
    
    int weight;
};

int solution(string dartResult) {
    
    vector<score_info> infos;
    bool is_prev_digit = false;
    
    for(size_t i = 0; i < dartResult.length(); i++)
    {
        if(dartResult[i] >= 48 && dartResult[i] <= 57)
        {
            if(is_prev_digit)
            {
                infos.back().score = 10;
                
                continue;
            }
            
            score_info info;
            info.score = int(dartResult[i] - '0');
            info.multiply = 1; 
            info.option = '\0';
            info.weight = 1;
            
            infos.push_back(info);
            
            is_prev_digit = true;
        }
        else if ('S' == dartResult[i] || 'D' == dartResult[i] || 'T' == dartResult[i])
        {
            switch(dartResult[i])
            {
                case 'S' : infos.back().multiply = 1;
                    break;
                case 'D' : infos.back().multiply = 2;
                    break;
                case 'T' : infos.back().multiply = 3;
                    break;
                default:
    
            }
            
            is_prev_digit = false;
        }
        else if ('*' == dartResult[i] || '#' == dartResult[i])
        {
            infos.back().option = dartResult[i];
            
            if('*' == dartResult[i])
            {
                infos.back().weight *= 2;
                
                if(infos.size() > 1)
                {
                    infos[infos.size() - 2].weight *= 2;
                }
            }
            else if ('#' == dartResult[i])
            {
                infos.back().weight *= -1;
            }
            
            is_prev_digit = false;
        }
    }
    
    int answer = 0;
    for(size_t i = 0; i < infos.size(); i++)
    {
        int score = infos[i].score;
        for(int j = 1; j < infos[i].multiply; j++)
        {
            score *= infos[i].score;
        }
        
        score *= infos[i].weight;
    
        answer += score;
    }
    
    return answer;
}