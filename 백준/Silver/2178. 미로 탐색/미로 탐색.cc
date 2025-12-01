#include <bits/stdc++.h>

using namespace std;

constexpr int max_n = 104;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;
int y, x;
int ny, nx;
int start_location[max_n][max_n], visited[max_n][max_n];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string input_string;
        cin >> input_string;
        for (int j = 0; j < m; ++j)
        {
            start_location[i][j] = input_string[j] - '0';
        }
    }
    
    int start_y = 0, start_x = 0;
    int end_y = n - 1, end_x = m - 1;

    queue<pair<int, int>> Queue;

    // 시작위치는 방문처리
    visited[start_y][start_x] = 1;
    
    // 탐색 시작할 좌표 등록
    Queue.push({start_y, start_x});

    while (!Queue.empty())
    {
        tie(y, x) = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || start_location[ny][nx] == 0 || visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            Queue.push({ny, nx});
        }
    }

    cout << visited[end_y][end_x];
    
    return 0;
}