#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
  sort(score.begin(), score.end(), greater<int>());

  int total = 0;
  for (size_t i = 0; i + m <= score.size(); i += m)
  {
    int min = score[i + m - 1];
    total += min * m;
  }
    
    return total;
}
