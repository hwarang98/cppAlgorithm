#include<bits/stdc++.h>

using namespace std;

int n, k, temp, pusm[100001], ret = -10000004;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        pusm[i] = pusm[i - 1] + temp;
    }

    for (int i = k; i <= n; ++i)
    {
        ret = max(ret, pusm[i] - pusm[i - k]);
    }

    cout << ret << "\n";
    return 0;
}