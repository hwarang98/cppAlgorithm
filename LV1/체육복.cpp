#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 1. 도난 + 여벌 중복 제거
    vector<int> pureLost, pureReserve;

    for (int l : lost)
    {
        // 여벌 있는 학생이면 (겹치는 경우)
        auto it = find(reserve.begin(), reserve.end(), l);
        if (it != reserve.end())
        {
            reserve.erase(it); // reserve에서 제거
        }
        else
        {
            pureLost.push_back(l); // 진짜 잃어버린 사람
        }
    }

    pureReserve = reserve; // 여벌만 가진 사람들

    // 2. 체육복 빌려주기 (앞뒤 학생 확인)
    for (auto it = pureLost.begin(); it != pureLost.end(); )
    {
        int l = *it;
        auto prev = find(pureReserve.begin(), pureReserve.end(), l - 1);
        auto next = find(pureReserve.begin(), pureReserve.end(), l + 1);

        if (prev != pureReserve.end())
        {
            pureReserve.erase(prev);
            it = pureLost.erase(it); // 성공적으로 빌렸으므로 lost에서 제거
        }
        else if (next != pureReserve.end())
        {
            pureReserve.erase(next);
            it = pureLost.erase(it);
        }
        else
        {
            ++it; // 못 빌렸으면 다음 사람으로
        }
    }

    // 3. 최종 수업 가능한 학생 수
    return n - pureLost.size();
}
