#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    vector<int> dw = {1, 0, 0, -1};
    vector<int> dh = {0, 1, -1, 0};
    
    for(size_t i = 0; i < dw.size(); i++)
    {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        
        if ( (h_check >= 0 && h_check < board.size()) && 
            (w_check >= 0 && w_check <= board.size()) )
        {
            if(board[h_check][w_check] == board[h][w])
            {
                answer++;
            }
        }
    }
    
    return answer;
}