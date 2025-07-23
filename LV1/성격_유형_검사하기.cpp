#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> m;

    // choice 1~7 → 점수 매핑: index 그대로 사용
    vector<int> score_map = {3, 2, 1, 0, 1, 2, 3};

    for (size_t i = 0; i < survey.size(); i++) {
        char disagree = survey[i][0];
        char agree = survey[i][1];
        int choice = choices[i];

        if (choice < 4) {
            m[disagree] += score_map[choice-1];
        } else if (choice > 4) {
            m[agree] += score_map[choice-1];
        }
        // choice == 4는 중립이므로 무시
    }

    // 성격 유형 결정
    answer += (m['R'] >= m['T']) ? 'R' : 'T';
    answer += (m['C'] >= m['F']) ? 'C' : 'F';
    answer += (m['J'] >= m['M']) ? 'J' : 'M';
    answer += (m['A'] >= m['N']) ? 'A' : 'N';

    return answer;
}
