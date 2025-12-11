#include <bits/stdc++.h>
using namespace std;

#define y1 aaaa   // y1 이름 충돌 방지용 매크로(BOJ에서 흔히 사용)

int dy[4] = {0, -1, 0, 1};   // 상하좌우 이동(y 방향)
int dx[4] = {1, 0, -1, 0};   // 상하좌우 이동(x 방향)

int m, n, k, x1, x2, y1, y2;

int visited[101][101];   // 방문 체크 배열
int MAP[101][101];       // 지도: 1 = 막힌 영역(사각형 내부), 0 = 빈 칸

vector<int> result;      // 각각의 영역 크기 저장

// DFS로 연결된 빈 구역의 넓이(칸 수) 계산
int DFS(const int y, const int x)
{
    visited[y][x] = 1;   // 현재 위치 방문 처리
    int count = 1;       // 현재 칸 포함

    // 4방향 탐색
    for (int i = 0; i < 4; ++i)
    {
        const int ny = y + dy[i];
        const int nx = x + dx[i];

        // 범위 밖, 방문함, 사각형 영역 내부일 경우 skip
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1 || MAP[ny][nx] == 1) continue;
        count += DFS(ny, nx);  // 연결된 영역 크기 누적
    }

    return count;  // 현재 영역 크기 반환
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;   // m = 세로, n = 가로, k = 사각형 개수

    // k개의 사각형 입력 받아 지도에 표시
    for (int i = 0 ; i < k; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;   // (x1, y1) ~ (x2, y2) 직사각형

        // 해당 구역 MAP에 1로 표시 (막힌 영역)
        for (int x = x1; x < x2; ++x)
        {
            for (int y = y1; y < y2; ++y)
            {
                MAP[y][x] = 1;
            }
        }
    }

    // 전체 MAP 순회하여 빈 영역(0) 중 방문 안한 곳 찾기
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // 방문 안했고, 사각형(막힌 곳)이 아니라면 새로운 구역 시작
            if (visited[i][j] == 0 && MAP[i][j] != 1)
            {
                result.push_back(DFS(i, j)); // DFS로 영역 넓이 계산 후 저장
            }
        }
    }

    sort(result.begin(), result.end());   // 영역 크기 오름차순 정렬

    cout << result.size() << '\n';        // 총 영역 개수 출력

    for (int a : result)   // 각 영역 넓이 출력
    {
        cout << a << " ";
    }
    
    return 0;
}
