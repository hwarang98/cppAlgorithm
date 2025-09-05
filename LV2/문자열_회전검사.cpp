#include <string>
#include <vector>
#include <stack>

using namespace std;

bool IsValid(const string& s)
{
    // ( [ { 가 나오면 stack에 push
    // ) ] } 가 나오면 스택에서 짝이맞는지 판별
    stack<char> stringStack;

    for (const char& stack : s)
    {
        if (stack == '(' || stack == '[' || stack == '{')
        {
            stringStack.push(stack);
        }
        else
        {
            if (stringStack.empty())
            {
                return false;
            }
            
            char topString = stringStack.top();
            
            if (
                (stack == ')' && topString != '(') ||
                (stack == ']' && topString != '[') ||
                (stack == '}' && topString != '{'))
                {
                    return false;
                }
            stringStack.pop();
        }
    }

    return stringStack.empty();
}

int solution(string s) {
    int answer = 0;

    int size = s.size();

    for (int i = 0; i < size; ++i)
    {
        if (IsValid(s))
        {
            answer++;
        }

        s = s.substr(1) + s[0];
    }
    return answer;
}
