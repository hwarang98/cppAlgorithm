#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;

  set<int> win_nums_set(win_nums.begin(), win_nums.end());

  int zero_count = 0;
  int know_count = 0;
  for (const int& lotto_num: lottos)
  {
    if (lotto_num == 0)
    {
      zero_count++;
    }
    else
    {
      if (win_nums_set.count(lotto_num))
      {
        know_count++;
      }
    }
  }
  int max_match = know_count + zero_count;
  int min_match = know_count;

  int rank[] = {6, 6, 5, 4, 3, 2, 1};

  int best_rank = rank[max_match];
  int worst_rank = rank[min_match];

  
  return {best_rank, worst_rank};
}

