#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < score.size(); ++i) {
        minHeap.push(score[i]);

        // 명예의 전당 인원 수가 k 초과 시 가장 낮은 점수 제거
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // 현재 명예의 전당의 최하위 점수 저장
        answer.push_back(minHeap.top());
    }

    return answer;
}

int main() {
    vector<int> result = solution(3, {10, 100, 20, 150, 1, 100, 200});
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
