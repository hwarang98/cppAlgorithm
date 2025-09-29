#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int timeToMin(const string &s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    int baseTime = fees[0], baseFee = fees[1];
    int unitTime = fees[2], unitFee = fees[3];

    map<string, int> inTime;     // 차량 번호 -> 마지막 입차 시각
    map<string, int> totalTime;  // 차량 번호 -> 총 누적 주차 시간

    for (auto &rec : records) {
        stringstream ss(rec);
        string timeStr, car, state;
        ss >> timeStr >> car >> state;

        int t = timeToMin(timeStr);

        if (state == "IN") {
            inTime[car] = t;
        } else { // OUT
            totalTime[car] += t - inTime[car];
            inTime.erase(car);
        }
    }

    // 출차 안 한 차량 처리 (23:59 출차 간주)
    for (auto &p : inTime) {
        totalTime[p.first] += (1439 - p.second);
    }

    // 차량 번호 오름차순으로 요금 계산
    vector<int> answer;
    for (auto &p : totalTime) {
        int t = p.second;
        int fee = baseFee;
        if (t > baseTime) {
            fee += ((t - baseTime) + unitTime - 1) / unitTime * unitFee;
        }
        answer.push_back(fee);
    }
    return answer;
}