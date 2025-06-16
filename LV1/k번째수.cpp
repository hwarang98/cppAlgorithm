#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  for (const auto& cmd : commands)
  {
    vector<int> sliced(array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
    sort(sliced.begin(), sliced.end());
    answer.push_back(sliced[cmd[2] - 1]);
  }
  
  return answer;
}
