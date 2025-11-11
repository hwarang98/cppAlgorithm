#include <bits/stdc++.h>
using namespace std;

long long LongNum;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (scanf("%d", &n) != EOF)
    {
        long long cnt = 1;
        long long ret = 1; // 자릿수 체킹
        
        while (true)
        {
            if (cnt % n == 0) // n의 배수일때
            {
                printf("%lld\n", ret);
                break;
            }
            cnt = cnt * 10 + 1;
            cnt %= n;
            ret++;
        }
    }
    return 0;
}