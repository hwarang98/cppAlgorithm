#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
  string answer = "";
  
  for (char c : s) {
    if (isupper(c)) {
      answer += (c - 'A' + n) % 26 + 'A'; 
    } 
      else if (islower(c)) {
      answer += (c - 'a' + n) % 26 + 'a';
    } 
      else {
      answer += c; // 공백 등은 그대로
    }
  }

  
  return answer;
}
