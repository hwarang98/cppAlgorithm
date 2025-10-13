#include <string>
#include <vector>

using namespace std;

vector<string> dict;
vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};

// DFS로 모든 가능한 단어 생성
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

    for (char c : vowels)
    {
        dfs(current + c);
    }
}

int solution(string word) {
    dfs(""); // 사전 전체 생성
    
    // 사전은 이미 사전순으로 생성됨
    for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == word) return i + 1;
    }
    
    return -1; // 이론상 도달 안함
}
