#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
  int answer = 0;
  if (n < 2) return 0;
  
  while (n >= a)
  {
    int newCola = (n / a) * b;
    answer += newCola;
    n = (n % a) + newCola;  // 남은병 + 마신 콜라의 빈병
  }
  return answer;
}
