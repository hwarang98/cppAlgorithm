#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
        unordered_map<string, int> want_map;
    int total = 0;
    
    for (size_t i = 0; i < want.size(); ++i)
    {
        want_map[want[i]] = number[i];
        total += number[i];
    }

    int answer = 0;
    for (size_t i = 0; i + 9 < discount.size(); ++i)
    {
        unordered_map<string, int> cached_map;
        for (size_t j = i; j < i + 10; ++j)
        {
            cached_map[discount[j]]++;
        }

        bool ok = true;

        for (const auto &want_element : want_map)
        {
            if (cached_map[want_element.first] != want_element.second)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            answer++;
        }
    }
    return answer;
}
