#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    const int number = 1234567;
    
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int prev1 = 0;
    int prev2 = 1;
    
    for (int i = 2; i <= n; ++i)
    {
        answer = (prev1 + prev2) % number;
        prev1 = prev2;
        prev2 = answer;
    }
    
    return answer;
}
