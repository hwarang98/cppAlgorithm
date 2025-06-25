#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;

    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int firstCount = 0;
    int secondCount = 0;
    int thirdCount = 0;

    for (size_t i = 0; i < answers.size(); i++) {
        if (answers[i] == first[i % first.size()]) ++firstCount;
        if (answers[i] == second[i % second.size()]) ++secondCount;
        if (answers[i] == third[i % third.size()]) ++thirdCount;
    }

    int maxScore = max({firstCount, secondCount, thirdCount});

    if (firstCount == maxScore) result.push_back(1);
    if (secondCount == maxScore) result.push_back(2);
    if (thirdCount == maxScore) result.push_back(3);
    return result;
}
