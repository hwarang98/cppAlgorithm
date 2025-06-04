#include <string>
#include <vector>
#include <algorithm>  // reverse

using namespace std;


// 10진수 → 3진법 문자열
string toBase3(int n) {
    if (n == 0) return "0";

    string result = "";
    while (n > 0) {
        result += to_string(n % 3);  // 뒤에 붙이기 → 나중에 reverse
        n /= 3;
    }
    reverse(result.begin(), result.end());
    return result;
}

// 3진법 문자열 → 10진수
int fromBase3(const string& s) {
    int result = 0;
    for (char c : s) {
        result = result * 3 + (c - '0');
    }
    return result;
}

int solution(int n) {
    string base3 = toBase3(n);
    reverse(base3.begin(), base3.end());
    return fromBase3(base3);
}
