#include <bits/stdc++.h>

using namespace std;

int direction_y[4] = {-1, 0, 1, 0};
int direction_x[4] = {0, 1, 0, -1};

int test_case;
int m, n, k, ny, nx, y, x, result;
int visited[52][52];
int MAP[52][52];

void DFS(const int y, const int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i)
    {
        ny = y + direction_y[i];
        nx = x + direction_x[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!visited[ny][nx] && MAP[ny][nx] == 1) DFS(ny, nx);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> test_case;

    while (test_case--)
    {
        // 새로운 testcase마다 초기화
        fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
        fill(&MAP[0][0], &MAP[0][0] + 52 * 52, 0);
        result = 0;

        cin >> m >> n >> k;

        // MAP 생성
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            MAP[y][x] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // MAP[i][j] == 1 탐색할수있는 칸인가?, !visited[i][j] = 아직 방문한 적 없는가? 
                if (MAP[i][j] == 1 && !visited[i][j])
                {
                    DFS(i, j);
                    result++;
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}


