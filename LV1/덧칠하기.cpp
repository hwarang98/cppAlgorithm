#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    sort(section.begin(), section.end()); // 정렬
    
    int paintEnd = 0; // 이번 칠하기가 커버하는 구역 끝 번호
    
    for (int i = 0; i < section.size(); ++i) {
        // 아직 이번 칠하기 커버 구역 밖이라면 새로운 칠하기 시작
        if (section[i] > paintEnd) {
            answer++; // 칠하기 횟수 증가
            paintEnd = section[i] + m - 1; // 롤러 길이만큼 커버
        }
        // section[i] <= paintEnd면 이미 칠한 구역 안이므로 넘어감
    }
    
    return answer;
}


    
