#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i = 1; i <= n; i++){
        answer.push_back((long long)x * i); // x씩 증가하는 숫자 추가
    }
    return answer;
}
