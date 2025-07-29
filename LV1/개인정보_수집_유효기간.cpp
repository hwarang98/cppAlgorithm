#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int convertToDays(const string& date) {
    istringstream iss(date);
    int y, m, d;
    char dot;
    iss >> y >> dot >> m >> dot >> d;
    return y * 12 * 28 + m * 28 + d;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<string, int> termLimits;
    
    for (const string& term : terms) {
        istringstream iss(term);
        string type;
        int months;
        iss >> type >> months;
        termLimits[type] = months;
    }

    int todayDays = convertToDays(today);
    vector<int> answer;

    for (size_t i = 0; i < privacies.size(); ++i) {
        istringstream iss(privacies[i]);
        string date, type;
        iss >> date >> type;

        int collectedDays = convertToDays(date);
        int expiryDays = collectedDays + termLimits[type] * 28;

        if (expiryDays <= todayDays) {
            answer.push_back(i + 1); // 개인정보 번호는 1부터 시작
        }
    }
    
    return answer;
}
