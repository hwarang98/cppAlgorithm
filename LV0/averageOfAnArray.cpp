#include <string>
#include <vector>
#include <numeric>   // accumulate, plus

using namespace std;

double solution(vector<int> numbers) {

    // 1. 벡터 numbers의 합을 구함
    int sum = accumulate(begin(numbers), end(numbers), 0);

    // 2. 평균 계산 (sum을 double로 형변환한 뒤 크기로 나눔)
    return (double)sum / numbers.size();

}
