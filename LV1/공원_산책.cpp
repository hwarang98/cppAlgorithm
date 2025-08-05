#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int h = park.size();
    int w = park[0].size();

    int x = 0, y = 0;

    // 시작 위치 찾기
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (park[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    // 방향 매핑
    unordered_map<char, pair<int, int>> dir = {
        {'E', {0, 1}},
        {'W', {0, -1}},
        {'S', {1, 0}},
        {'N', {-1, 0}},
    };

    // 명령 수행
    for (const string& route : routes) {
        char d = route[0];
        int distance = stoi(route.substr(2));

        bool canMove = true;
        for (int step = 1; step <= distance; ++step) {
            int nx = x + dir[d].first * step;
            int ny = y + dir[d].second * step;

            if (nx < 0 || ny < 0 || nx >= h || ny >= w || park[nx][ny] == 'X') {
                canMove = false;
                break;
            }
        }

        if (canMove) {
            x += dir[d].first * distance;
            y += dir[d].second * distance;
        }
    }

    return {x, y};
}
