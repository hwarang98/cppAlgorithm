#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, unordered_set<string>> reportMap;
    unordered_map<string, int> userIndex;

    for (int i = 0; i < id_list.size(); ++i)
    {
        userIndex[id_list[i]] = i;
    }

    for (const string& r : report)
    {
        size_t spacePos = r.find(' ');
        string reporter = r.substr(0, spacePos); // 신고한 사람
        string reported = r.substr(spacePos + 1); // 신고당한 사람

        reportMap[reported].insert(reporter);
    }

    for (const auto& entry : reportMap)
    {
        if (entry.second.size() >= k)
        {
            for (const string& reporter : entry.second)
            {
                answer[userIndex[reporter]]++;
            }
        }
    }
    
    return answer;
}
