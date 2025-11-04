#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int materialTotalCount, numberOfArmor;
    cin >> materialTotalCount >> numberOfArmor;

    vector<int> materialArray(materialTotalCount);
    for (int i = 0; i < materialTotalCount; ++i)
        {
            cin >> materialArray[i];
        }

    sort(materialArray.begin(), materialArray.end());

    int left = 0;
    int right = materialTotalCount - 1;
    int result = 0;

    while (left < right) {
        int sum = materialArray[left] + materialArray[right];

        if (sum == numberOfArmor) {
            result++;
            left++;
            right--;
        }
        else if (sum < numberOfArmor) {
            left++;  // 합을 키움
        }
        else {
            right--; // 합을 줄임
        }
    }

    cout << result << "\n";
    return 0;
}

