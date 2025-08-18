#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool newWord = true;
    for (char& c : s)
    {
        if (c == ' ')
        {
            newWord = true; // 공백이면 다음 문자가 새 단어
        }
        else
        {
            if (newWord)
            {
                c = toupper(c);
                newWord = false;
            }
            else
            {
                c = tolower(c);
            }
        }
    }

    return s;
}
