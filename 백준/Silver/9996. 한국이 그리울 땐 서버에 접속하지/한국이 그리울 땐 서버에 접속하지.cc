#include<bits/stdc++.h>

using namespace std;

int fileCount;
string pattern, word;

int main(){
    cin >> fileCount >> pattern;
    int startPos = pattern.find('*');
    string prefix = pattern.substr(0, startPos);
    string suffix = pattern.substr(startPos + 1);

    while (fileCount--)
    {
        cin >> word;
        
        if (word.size() < prefix.size() + suffix.size())
        {
            cout << "NE" << "\n";
            continue;
        }

        
        
        if (word.substr(0, prefix.size()) == prefix && word.substr(word.size() - suffix.size()) == suffix)
        {
            cout << "DA" << "\n";
        }
        else
        {
            cout << "NE" << "\n";
        }
    }

    return 0;
}