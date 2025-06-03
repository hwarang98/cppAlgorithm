#include <string>
#include <vector>

using namespace std;

vector<vector<int>> matrixAdd(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int row = A.size();
    int col = A[0].size();  // 열 크기 A 기준으로 잡기

    vector<vector<int>> result(row, vector<int>(col)); 
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return result;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    return matrixAdd(arr1, arr2);
}
