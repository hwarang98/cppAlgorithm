#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long rotationCount = num;
    
    while(rotationCount != 1){
        rotationCount = rotationCount % 2 == 0 ? rotationCount / 2 : rotationCount * 3 + 1 ; 
        answer++;
        
        if(answer >= 500) {
            return -1;
        }
    }
    return answer;
}
