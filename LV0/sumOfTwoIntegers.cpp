#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    long long start = min(a, b); // a, b를 비교해서 작은 수 -> 3
    long long end = max(a, b); // // a, b를 비교해서 큰 수 -> 5
    
    // 등차수열의 합
    // (첫항 + 마지막항) * 항의갯수 / 2
    return (start + end) * (end - start + 1) / 2;

}
