#include <bits/stdc++.h>
using namespace std;

// n: 스크린 크기, m: 바구니 크기, j: 사과 개수
// left_location: 바구니의 현재 왼쪽 끝 좌표 (초기값 1)
// right_location: 바구니의 현재 오른쪽 끝 좌표
// drop_location: 떨어지는 사과의 위치
// result: 바구니의 총 이동 거리
int n, m, j, left_location = 1, right_location, drop_location, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> j;

    // 사과가 떨어지기 시작 (총 j개)
    for (int i = 0 ; i < j; ++i)
    {
        cin >> drop_location;
        
        // 현재 바구니의 오른쪽 끝 위치 갱신
        right_location = left_location + m - 1;

        // 1. 사과가 바구니보다 왼쪽에 떨어질 때
        if (drop_location < left_location)
        {
            result += left_location - drop_location;
            left_location = drop_location;
        }
        // 2. 사과가 바구니보다 오른쪽에 떨어질 때
        else if (drop_location > right_location)
        {
            result += drop_location - right_location;
            left_location += drop_location - right_location;
        }
        // 3. 그 외 (바구니 안) -> 아무것도 안 함 (자동 통과)
    }

    cout << result << "\n";
    return 0;
}