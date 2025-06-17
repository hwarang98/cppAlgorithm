#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
  vector<int> result;
  unordered_map<char, int> lastIdx;  // 각 문자별 마지막 등장 인덱스 저장

  for (size_t i = 0; i < s.size(); ++i) {
    char c = s[i];
    
    if (lastIdx.find(c) == lastIdx.end()) {
      result.push_back(-1);
    } else {
      result.push_back(i - lastIdx[c]);
    }
    lastIdx[c] = i;  // 현재 위치로 업데이트
  }

  return result;
}
