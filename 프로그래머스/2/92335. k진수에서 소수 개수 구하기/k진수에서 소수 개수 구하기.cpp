#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

string to_base(long long n, int k) {
    string result = "";
    while (n > 0) {
        result += to_string(n % k);
        n /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

// 소수 판별
bool is_prime(const long long num) {
    if (num < 2)
    {
        return false;
    }
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    // n을 k 진수로 변경
    // k진수로 변경된 숫자 탐색
    // 0P0, P0, 0P, P 의 조건에 맞으면 answer++

    string base = to_base(n, k);
    int count = 0;

    string current;
    for (char c : base)
    {
        if (c == '0')
        {
            if (!current.empty())
            {
                long long val = stoll(current);
                if (is_prime(val))
                {
                    count++;
                }
            }
            current = "";
        }
        else
        {
            current += c;
        }
    }

    if (!current.empty())
    {
        long long val = stoll(current);
        if (is_prime(val))
        {
            count++;
        }
    }
    
    return count;
}