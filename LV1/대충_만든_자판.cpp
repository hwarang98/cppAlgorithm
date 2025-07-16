#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {

    vector<int> answer;
    unordered_map<char, int> pressedKeyMap;

    for (const string& key : keymap)
    {
        for (size_t i = 0; i < key.size(); ++i)
        {
            char ch = key[i];
            int pressCount = i + 1;

            if (pressedKeyMap.find(ch) == pressedKeyMap.end())
            {
                pressedKeyMap[ch] = pressCount;
            }
            else
            {
                pressedKeyMap[ch] = min(pressedKeyMap[ch], pressCount);
            }
        }
    }

    for (const string& target : targets)
    {
        int totalPress = 0;
        bool valid = true;
        {
            for (char ch : target)
            {
                if (pressedKeyMap.find(ch) == pressedKeyMap.end())
                {
                    valid = false;
                    break;
                }
                totalPress += pressedKeyMap[ch];
            }
            answer.push_back(valid ? totalPress : -1);
        }
    }


    return answer;
}
