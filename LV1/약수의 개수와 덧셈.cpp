#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getDivisors(int n) {
    std::vector<int> divisors;

    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}



int solution(int left, int right) {
    int answer = 0;
    for (int num = left; num <= right; ++num) {
        int divCount = getDivisors(num).size();
        if (divCount % 2 == 0) {
            answer += num;  // 약수 개수 짝수면 더하기
        } else {
            answer -= num;  // 홀수면 빼기
        }
    }
    return answer;
}

