#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(string s) {
    const int sLength = s.length();
    int middle = sLength / 2; // 정수 나눗셈, floor() 불필요
    return sLength % 2 == 1 ? string(1, s[middle]) : s.substr(middle - 1, 2);
  
}
