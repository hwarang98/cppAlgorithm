#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int MAP[101][101];

string quard(const int y, const int x, const int size)
{
    if (size == 1) return string(1, MAP[y][x]);

    const char c = MAP[y][x];
    string result = "";

    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++ j)
        {
            if (c != MAP[i][j])
            {
                result += '(';
                result += quard(y, x, size / 2); // 왼쪽 위 
                result += quard(y, x + size / 2, size / 2); // 오른쪽 위
                result += quard(y + size / 2, x, size / 2); // 왼쪽 아래
                result += quard(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
                result += ')';
                return result;
            }
        }
    }
    
    return string(1, c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            MAP[i][j] = s[j];
        }
    }

    cout << quard(0, 0 ,n) << '\n';
    
    return 0;
}
