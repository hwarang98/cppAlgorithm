#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int solution(string s) {
    int n = s.size();
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (isValid(s)) answer++;
        // 문자열 왼쪽 회전
        s = s.substr(1) + s[0];
    }
    return answer;
}
