#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[26];
string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (char a : str)
    {
        cnt[a - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << cnt[i] << " ";
    }

    return 0;
}