#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] % divisor == 0){
            answer.push_back(arr[i]);
        }
    }
    
    sort(answer.begin(), answer.end());  // 오름차순 정렬
    
    return answer.size() == 0 ? vector<int>(1, -1) : answer;
}
