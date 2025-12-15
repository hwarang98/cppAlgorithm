#include <bits/stdc++.h>
using namespace std;

int n, c, frequency, order, number;

struct NumberInfo
{
    int number;
    int frequency;
    int firstIndex;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    vector<int> number_array;
    map<int, NumberInfo> MAP;

    for (int i = 0; i < n; ++i)
    {
        cin >> number;
        number_array.push_back(number);
    }

    for (int i = 0; i < number_array.size(); ++i)
    {
        int number = number_array[i];

        // 첫 등장
        if (MAP.find(number) == MAP.end())
        {
            MAP[number] = {number, 1, i};
        }
        // 이미 등장했다면
        else
        {
            MAP[number].frequency++;
        }
    }

    vector<NumberInfo> sortedList;
    for (const auto& pair : MAP)
    {
        sortedList.push_back(pair.second);
    }

    sort(sortedList.begin(), sortedList.end(), [](const NumberInfo& a, const NumberInfo& b)
    {
        if (a.frequency != b.frequency) return a.frequency > b.frequency;
        return a.firstIndex < b.firstIndex;
    });

    for (const auto& info : sortedList)
    {
        for (int i = 0; i < info.frequency; ++i)
        {
            cout << info.number << " ";
        }
    }
    return 0;
}