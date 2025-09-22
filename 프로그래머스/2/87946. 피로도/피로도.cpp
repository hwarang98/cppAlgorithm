#include <string>
#include <vector>

using namespace std;

void dfs(int k, vector<vector<int>>& dungeons, int count, vector<bool>& visited, int& answer) {
    answer = max(answer, count);

    for (int i = 0; i < dungeons.size(); i++) {
        int minReq = dungeons[i][0];
        int consume = dungeons[i][1];

        if (!visited[i] && k >= minReq) {
            visited[i] = true;
            dfs(k - consume, dungeons, count + 1, visited, answer);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, 0, visited, answer);
    return answer;
}