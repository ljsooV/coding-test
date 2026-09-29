#include <string>
#include <algorithm>

using namespace std;

bool is_prime(long long n)
{
    if (n < 2) return false;

    // i * i의 오버플로 방지
    for (long long i = 2; i <= n / i; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    string s;
    while (n > 0)
    {
        s += char('0' + n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());

    s += '0';

    string part;
    for (char c : s)
    {
        if (c != '0')
        {
            part += c;
        }
        else if (!part.empty())
        {
            if (is_prime(stoll(part)))
            {
                answer++;
            }
            part.clear();
        }
    }

    return answer;
}