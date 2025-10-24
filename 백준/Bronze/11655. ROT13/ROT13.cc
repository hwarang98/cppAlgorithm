#include<bits/stdc++.h>

using namespace std;

string word;

int main(){
    getline(cin, word);

    // 대문자 소문자인경우
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] >= 65 && word[i] <= 90)
        {
            // 대문자인 경우
            if (word[i] + 13 > 90)
            {
                word[i] = word[i] + 13 - 26;
            }
            else
            {
                word[i] = word[i] + 13;
            }
        }

        if (word[i] >= 97 && word[i] <= 122)
        {
            // 소문자인 경우
            if (word[i] + 13 > 122)
            {
                word[i] = word[i] + 13 - 26;
            }
            else
            {
                word[i] = word[i] + 13;
            }
        }
        cout << word[i];
    }
    
    return 0;
}