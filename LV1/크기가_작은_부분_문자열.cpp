#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
  int answer = 0;
  int lenP = p.size();
  long long numP = stoll(p);  // 큰 숫자일 수도 있으니 stoll 사용

  for (int i = 0; i <= t.size() - lenP; ++i) {
    string sub = t.substr(i, lenP);
    long long numSub = stoll(sub);  // 부분 문자열도 숫자로

    if (numSub <= numP) {
      ++answer;
    }
  }

  return answer;
}
