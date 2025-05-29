#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    // 숫자 -> 문자열로 변경 int stringNumber
    // 문자열 반복 돌림 -> number[i]를 다 더해서 결과(sum)를담는 변수에 저장
    // x % sum == 0 ? true : false;
    string stringNumber = to_string(x);
    int sum = 0;
    
    for(int i = 0; i < stringNumber.size(); ++i){
        sum += stringNumber[i] - '0';
    }
    
    return x % sum == 0;
}
