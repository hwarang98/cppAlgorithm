#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clothes_map;

    for (const auto &clothe: clothes)
    {
        string type = clothe[1];
        clothes_map[type]++;
    }

    int answer = 1;

    for (const auto& items : clothes_map)
    {
        answer *= (items.second + 1);
    }
    
    
    return answer - 1;
}