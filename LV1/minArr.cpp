#include <string>
#include <vector>
#include <algorithm> // std::min_element

using namespace std;

vector<int> solution(vector<int> arr) {
        // 원소가 하나라면 [1] 반환
    if (arr.size() == 1) return {-1};
    
    auto min_it = min_element(arr.begin(), arr.end());
    
    int min_value = *min_it;
    
    vector<int> result;
    for(int num : arr){
        if(num != min_value){
            result.push_back(num);
        }
    }
    return result;
}
