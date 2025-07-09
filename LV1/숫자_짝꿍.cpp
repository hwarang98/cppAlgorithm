#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
  vector <int> countX(10, 0);
  vector <int> countY(10, 0);

  for (const char& ch : X) {
    countX[ch - '0']++;
  }

  for (const char& ch : Y) {
    countY[ch - '0']++;
  }


  string result = "";
  for (int i = 9; i >= 0; --i) {
    int common = min(countX[i], countY[i]);
    result += string(common, '0' + i);
  }


    if (result.empty()) return "-1";
    if (result == "0") return "0";
    
    bool allZero = true;
    
    for (char c : result) {
    if (c != '0') {
        allZero = false;
        break;
        }
    }
    
    if (allZero) return "0";
    return result;
}
