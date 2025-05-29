#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string stringNumber = to_string(n);
    sort(stringNumber.begin(), stringNumber.end(), greater<char>());
    
    return stoll(stringNumber);
}
