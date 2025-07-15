#include <string>

using namespace std;

int solution(string s) {
 int answer = 0;
    int count_x = 0, count_other = 0;
    char x = s[0];

    for (size_t i = 0; i < s.size(); ++i) {
        if (count_x == 0 && count_other == 0) {
            x = s[i];
        }

        if (s[i] == x) {
            count_x++;
        } else {
            count_other++;
        }

        if (count_x == count_other) {
            answer++;
            count_x = 0;
            count_other = 0;
        }
    }

    if (count_x != 0 || count_other != 0) {
        answer++;
    }

    return answer;
}
