#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }

    long long half = modPow(a, b / 2, c);
    long long result = half * half % c;
    if (b % 2 == 1)
    {
        result = result * a % c;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long inputNumberA, inputNumberB, inputNumberC;

    cin >> inputNumberA >> inputNumberB >> inputNumberC;

    cout << modPow(inputNumberA, inputNumberB, inputNumberC) << "\n";
    return 0;
}