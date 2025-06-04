#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {           // 세로: m줄 출력
        for (int j = 0; j < n; j++) {       // 가로: 각 줄마다 n개의 별 출력
            cout << "*";
        }
        cout << endl;                       // 줄바꿈
    }

    return 0;
}
