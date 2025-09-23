#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int target, int idx, int sum)
{
    if (idx == numbers.size())
    {
        return sum == target ? 1 : 0;
    }

    const int num_one = dfs(numbers, target, idx + 1, sum + numbers[idx]);
    const int num_two = dfs(numbers, target, idx + 1, sum - numbers[idx]);

    return num_one + num_two;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}