#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    const int completed = 100;
    vector<int> completed_days;
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); ++i)
    {
        int remain = completed - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i]; 
        completed_days.push_back(day);
    }

    int standard = completed_days[0];
    int count = 1;

    for (int i = 1; i < completed_days.size(); ++i)
    {
        if (completed_days[i] <= standard)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            count = 1;
            standard = completed_days[i];
        }
    }
    
    answer.push_back(count);
    return answer;
}