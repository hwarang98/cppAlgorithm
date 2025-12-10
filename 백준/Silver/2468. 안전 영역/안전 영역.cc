#include <bits/stdc++.h>

using namespace std;

const int direction_y[4] = {-1, 0, 1, 0};
const int direction_x[4] = {0, 1, 0, -1};

int n, ny, nx, y, x, result = 1;

int visited[104][104];
int MAP[104][104];

void DFS(const int y, const int x, const int depth)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i)
    {
        ny = y + direction_y [i];
        nx = x + direction_x[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (!visited[ny][nx] && MAP[ny][nx] > depth) DFS(ny, nx, depth);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    for (int d = 1; d <= 104; ++d)
    {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (MAP[i][j] > d && !visited[i][j])
                {
                    DFS(i, j, d);
                    count++;
                }
            }
        }
        result = max(result, count);
    }
    cout << result << '\n';

    return 0;
}