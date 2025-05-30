#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    // 1. absolutes를 하나씩 탐색한다.
    // 2. 만약 signs[i]가 false면 음수로 변환
    for (int i = 0; i < absolutes.size(); ++i) {
        if (!signs[i]) {
            absolutes[i] = -absolutes[i];
        }
    }
    
    int result = 0;
    for (int num : absolutes) {
        result += num;
    }
    
    return result;
}
