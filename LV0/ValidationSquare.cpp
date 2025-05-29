#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long square = static_cast<long long>(sqrt(n));
    
    return square * square == n ? (square + 1) * (square + 1) : -1;
    return answer;
}
