#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
  string answer = "";

  int idx = 0;
  for (char wording : s) {
    if (wording == ' ') {
      answer += ' ';
      idx = 0;  // 단어 인덱스 초기화
    } else {
      if (idx % 2 == 0) {
        answer += toupper(wording);
      } else {
        answer += tolower(wording);
      }
      idx++;
    }
  }
  return answer;
}

