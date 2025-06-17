#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> result;
    set<int> numbersSet;
    
    for (size_t i = 0; i < numbers.size() - 1; i++)
        for (size_t j = i + 1; j < numbers.size(); j++)
            numbersSet.insert(numbers[i] + numbers[j]);
    
    vector<int> numbersVector(numbersSet.begin(), numbersSet.end());
    return numbersVector;
}
