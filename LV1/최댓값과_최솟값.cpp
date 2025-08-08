#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    // 파싱을 위한 stringstream
    stringstream ss(s);

    // 최소·최대값 초기화
    int mn = numeric_limits<int>::max();
    int mx = numeric_limits<int>::min();
    int num;

    // 공백으로 구분된 각 숫자를 읽어들여 최소, 최대 갱신
    while (ss >> num) {
        mn = min(mn, num);
        mx = max(mx, num);
    }

    // "(최소값) (최대값)" 형태로 반환
    return to_string(mn) + " " + to_string(mx);
}
