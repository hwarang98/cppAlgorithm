#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> x, y;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    answer.push_back(*min_element(x.begin(), x.end()));
    answer.push_back(*min_element(y.begin(), y.end()));
    answer.push_back(*max_element(x.begin(), x.end()) + 1);
    answer.push_back(*max_element(y.begin(), y.end()) + 1);
    return answer;
}
