#include<bits/stdc++.h>

using namespace std;

constexpr int max_mn = 54;
constexpr int max_k = 2504;

int direction_y[4] = {-1, 0, 1, 0};
int direction_x[4] = {0, 1, 0, -1};

int t, m, n, k, ny, nx, ret, x, y;
int visited[max_mn][max_mn];
int MAP[max_mn][max_mn];

void DFS(const int y, const int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        ny = y + direction_y[i];
        nx = x + direction_x[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!visited[ny][nx] && MAP[ny][nx] == 1) DFS(ny, nx);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--)
    {
        fill(&MAP[0][0], &MAP[0][0] + max_mn * max_mn, 0);
        fill(&visited[0][0], &visited[0][0] + max_mn * max_mn, 0);
        ret = 0;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++)
        {
            // m = 가로길이, n = 세로길이, k = 배추가 심어져있는 위치
            cin >> x >> y;
            MAP[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (MAP[i][j] == 1 && !visited[i][j])
                {
                    DFS(i, j);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }

    return 0;
}