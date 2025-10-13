#include <string>
#include <vector>

using namespace std;
vector<string> dict;
vector<char> vowel = {'A', 'E', 'I', 'O', 'U'};

void dfs(string current)
{
    if (!current.empty())
    {
        dict.push_back(current);
    }

    if (current.size() == 5)
    {
        return;
    }

    for (char c : vowel)
    {
        dfs(current + c);
    }
}

int solution(string word)
{
    // 사전 생성
    dfs("");
    
    for (int i = 0; i < dict.size(); i++)
    {
        if (dict[i] == word)
        {
            return i + 1;
        }
    }
    return 1;
}
