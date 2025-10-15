#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    const int vector_size = numbers.size();
    
    vector<int> answer(vector_size, -1);
    stack<int> stack; // 뒷 큰수가 될 수 있는 후보들
    
    for (int i = vector_size - 1; i >= 0; --i)
    {

        // 현재 수보다 작거나 같은 수는 뒷 큰수가 될 수 없음
        while (!stack.empty() && stack.top() <= numbers[i])
        {
            stack.pop();
        }

        if (!stack.empty())
        {
            answer[i] = stack.top();
        }

        stack.push(numbers[i]);
    }
    return answer;
}
