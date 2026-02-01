#include <bits/stdc++.h>
using namespace std;

// lastTime : 직전 득점 시각 (초)
// leadTime1, leadTime2 : 각 팀이 이기고 있던 누적 시간(초)
int n, score1, score2, lastTime, lead1, lead2;

int toSec(const string& s)
{
    const int mm = stoi(s.substr(0, 2));
    const int ss = stoi(s.substr(3, 2));
    return mm * 60 + ss;
}

string toMMSS(int t)
{
    const int mm = t / 60;
    const int ss = t % 60;
    char buf[6];
    snprintf(buf, sizeof(buf), "%02d:%02d", mm, ss);
    return string(buf);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int team;
        string timeStr;
        cin >> team >> timeStr;
        const int currentTime = toSec(timeStr);
        
        // 1. 직전 구간 리드 시간 누적
        if (score1 > score2) lead1 += currentTime - lastTime;
        else if (score2 > score1) lead2 += currentTime - lastTime;
        
        // 2. 득점 반영
        if (team == 1) score1++;
        else score2++;
        
        lastTime = currentTime;
    }
    
    // 경기종료 (48:00)까지 마지막 구간 누적
    int endTime = 48 * 60;
    if (score1 > score2) lead1 += endTime - lastTime;
    else if (score2 > score1) lead2 += endTime - lastTime;
    
    cout << toMMSS(lead1) << "\n";
    cout << toMMSS(lead2) << "\n";
}