#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> Queue; // 우산순위, 인덱스
    
    for (int i = 0; i < priorities.size(); i++)
    {
        Queue.push({priorities[i], i});
    }

    int answer = 0;
    while (!Queue.empty())
    {
        auto current = Queue.front();
        Queue.pop();

        // 더 높은 우선순위 있는지 체크
        bool higher = false;
        for (const int &p : priorities)
        {
            if (p > current.first)
            {
                higher = true;
                break;
            }
        }

        if (higher)
        {
            Queue.push(current);
        }
        else
        {
            answer++;

            priorities.erase(find(priorities.begin(), priorities.end(), current.first));

            if (current.second == location)
            {
                cout << "answer: " << answer << endl;
                return answer;
            }
        }
    }

    return 1;
}