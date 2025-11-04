#include<bits/stdc++.h>

using namespace std;

int materialTotalCount, numberOfArmor, materialNumber, result;
vector<int> materialArray;


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);

    cin >> materialTotalCount >> numberOfArmor;


    for (int i = 0; i < materialTotalCount; ++i)
    {
        cin >> materialNumber;
        materialArray.emplace_back(materialNumber);
    }

    sort(materialArray.begin(), materialArray.end());
    
    
    for (int i = 0; i < materialArray.size(); i++)
    {
        for (int j = i + 1; j < materialArray.size(); j++)
        {
            if (materialArray[i] + materialArray[j] == numberOfArmor)
            {
                result++;
            }
        }
    }

    cout << result << "\n";
    
    return 0;
}