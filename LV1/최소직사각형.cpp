#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
  int maxWidth = 0;
  int maxHeight = 0;
  for (auto card : sizes)
  {
    int w = max(card[0], card[1]);
    int h = min(card[0], card[1]);

    maxWidth = max(maxWidth, w);
    maxHeight = max(maxHeight, h);
  }

  return maxWidth * maxHeight;
}
