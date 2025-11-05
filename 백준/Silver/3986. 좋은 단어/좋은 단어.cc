#include <bits/stdc++.h>
using namespace std;

int wordLength, goodWordCount;
string word;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> wordLength;;

    for (int i = 0; i < wordLength; ++i)
    {
        cin >> word;

        stack<char> wordStack;

        for (char c : word)
        {
            if (!wordStack.empty() && wordStack.top() == c)
            {
                wordStack.pop();
            }
            else
            {
                wordStack.push(c);
            }
        }

        if (wordStack.empty())
        {
            goodWordCount++;
        }
    }

    cout << goodWordCount << "\n";
    
    return 0;
}