#include<bits/stdc++.h>

using namespace std;

int clothCount, n;

string cloth, b;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> clothCount;
    while (clothCount--)
    {
        map<string, int> clothMap;

        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> cloth >> b;

            clothMap[b]++;
        }

        long long ret = 1;

        for (auto c : clothMap)
        {
            ret *= ((long long)c.second + 1);
        }

        ret--;
        cout << ret << "\n";
    }
    
    return 0;
}