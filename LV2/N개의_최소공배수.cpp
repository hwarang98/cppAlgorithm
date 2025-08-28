#include <string>
#include <vector>
#include <numeric>


using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    for (auto& number : arr)
    {     
        answer = lcm(answer, number);
    }
    return answer;
}
