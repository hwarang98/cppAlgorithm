#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<char>()); // 내림차순 정렬
    return s;
}
