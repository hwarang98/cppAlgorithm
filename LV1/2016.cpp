#include <string>

using namespace std;

string solution(int a, int b) {
    // 2016년 월별 일 수 (윤년이므로 2월은 29일)
    int month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 요일: 일요일부터 시작 (0 = SUN ~ 6 = SAT)
    string week_days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    // 1월 1일은 금요일 -> FRI = 5
    int total_days = 0;
    for (int i = 0; i < a - 1; ++i) {
        total_days += month_days[i];  // a 이전 달까지 총 일수 합
    }
    total_days += (b - 1); // 해당 달의 b일까지의 일수 (1일을 기준으로 0부터 계산)

    // 요일 인덱스 계산
    int day_index = (5 + total_days) % 7;

    return week_days[day_index];
}
