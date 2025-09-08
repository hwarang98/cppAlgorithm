#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    vector<int> extended_elements;

    extended_elements.insert(extended_elements.end(), elements.begin(), elements.end());
    extended_elements.insert(extended_elements.end(), elements.begin(), elements.end());

    set<int> sums;

    for (int i = 0; i < elements.size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j < elements.size(); ++j)
        {
            sum += extended_elements[i + j];
            sums.insert(sum);
        }
    }
    
    
    return sums.size();
}
