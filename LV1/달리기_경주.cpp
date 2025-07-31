#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rank;

    for (int i = 0; i < players.size(); ++i)
    {
        rank[players[i]] = i;
    }

    for (const string& calling : callings)
    {
        int currentCallingRank = rank[calling];
        string frontRankName = players[currentCallingRank - 1];

        swap(players[currentCallingRank - 1], players[currentCallingRank]);

        rank[calling]--;
        rank[frontRankName]++;
    }
    
    return players;
}
