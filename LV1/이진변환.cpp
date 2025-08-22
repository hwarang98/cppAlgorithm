#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열 길이를 이진 문자열로 변환하는 함수
string toBinary(int n) {
    string result = "";
    while (n > 0) {
        result = char('0' + (n % 2)) + result;
        n /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    int countZero = 0; // 제거된 0의 총 개수
    int countTransform = 0; // 이진 변환 수행 횟수

    while (s != "1") {
        int onesCount = 0; // 1의 개수 = 0 제거 후 길이

        // 0 제거 + 1 개수 세기
        for (char c : s) {
            if (c == '1') onesCount++;
            else countZero++; // 0 개수 누적
        }

        // 길이를 2진 문자열로 변환
        s = toBinary(onesCount);
        countTransform++;
    }

    return {countTransform, countZero};
}
