#include <bits/stdc++.h>
using namespace std;

int n, m, j, left_location = 1, right_location, drop_location, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> j;

    for (int i = 0; i < j; ++i)
    {
        cin >> drop_location;
        right_location = left_location + m - 1;

        // 왼쪽에서 떨어질때
        if (drop_location < left_location)
        {
            // 위치 계산 (왼쪽 끝 지점 - 떨어지는 지점)
            result += left_location - drop_location;

            // 왼쪽 끝 지점 갱신
            left_location = drop_location;
        }
        // 오른쪽에서 떨어질때
        else if (drop_location > right_location)
        {
            result += drop_location - right_location;

            left_location += drop_location - right_location;
        }
    }

    cout << result << "\n";
    return 0;
}