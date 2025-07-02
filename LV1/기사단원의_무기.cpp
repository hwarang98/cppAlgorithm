#include <string>
#include <vector>

using namespace std;

int countDivisors(int n) {
	if (n <= 0) return 0; // 0 이하의 수는 약수를 정의하기 어렵
	if (n == 1) return 1; // 1의 약수는 1개

	int count = 0;
	for (int i = 1; i * i <= n; ++i) { // i * i <= n 조건을 사용하면 sqrt(n)까지 반복하는 것과 유사
		if (n % i == 0) { // i가 n의 약수라면
			if (i * i == n) { // i가 n의 제곱근인 경우 (예: n=9, i=3)
				count++; // 약수 1개만 카운트
			} else { // i와 n/i가 다른 약수인 경우 (예: n=12, i=2 -> 2와 6)
				count += 2; // 약수 2개 카운트 (i와 n/i)
			}
		}
	}
	return count;
}

int solution(int number, int limit, int power) {
	int answer = 0;
	for (int i = 1; i <= number; ++i) { // 1부터 number까지 각 숫자에 대해 반복
		int current_num_divisors = countDivisors(i); // 현재 숫자의 약수 개수를 계산

		if (current_num_divisors > limit)
		{
			answer += power;
		}
		else
		{
			answer += current_num_divisors;
		}
	}
	return answer;
}
