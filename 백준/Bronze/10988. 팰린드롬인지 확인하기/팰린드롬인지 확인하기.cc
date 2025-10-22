#include<bits/stdc++.h>

using namespace std;

string word, reverse_string;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> word;
    reverse_string = word;

    reverse(reverse_string.begin(), reverse_string.end());

    if (word == reverse_string) cout << 1;
    else cout << 0;
    return 0;
}