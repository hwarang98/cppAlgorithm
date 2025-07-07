#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const string& word, const vector<string>& sounds)
{
  string temp = word;
  string prev = "";

  while (!temp.empty()) {
    bool matched = false;

    for (const string& sound : sounds) {
      if (prev == sound) continue;  // 같은 발음이 연속되면 안 됨

      if (temp.find(sound) == 0) {  // 앞부분부터 일치하는 발음 찾기
        temp = temp.substr(sound.length());
        prev = sound;
        matched = true;
        break;
      }
    }

    if (!matched) return false;  // 어떤 발음과도 매칭되지 않음
  }
  return true;
}


int solution(vector<string> babbling) {
  int answer = 0;
  vector<string> validSounds = {"aya", "ye", "woo", "ma"};

  for (const string& word : babbling) {
    if (isValid(word, validSounds)) {
      answer++;
    }
  }
  
  return answer;
}
