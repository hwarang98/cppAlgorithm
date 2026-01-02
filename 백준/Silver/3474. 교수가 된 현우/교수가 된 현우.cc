#include <bits/stdc++.h>
using namespace std;

int n;
long long a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    while (n--) {
        cin >> a;

        long long cnt5 = 0;
        for (long long i = 5; i <= a; i *= 5) {
            cnt5 += a / i;
        }

        cout << cnt5 << '\n';
    }
    return 0;
}