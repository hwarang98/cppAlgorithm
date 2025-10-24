#include<bits/stdc++.h>

using namespace std;

int main() {
    string word;
    getline(cin, word);

    for (char& c : word) {
        if (isupper(c)) {
            // 대문자인 경우 'A'를 기준으로 13칸 회전
            c = 'A' + (c - 'A' + 13) % 26;
        }
        else if (islower(c)) {
            // 소문자인 경우 'a'를 기준으로 13칸 회전
            c = 'a' + (c - 'a' + 13) % 26;
        }
        // 알파벳이 아닌 경우는 그대로 둠
        cout << c;
    }

    return 0;
}