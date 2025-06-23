#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
  size_t firstIndex = 0;
  size_t secondIndex = 0;
  for (const string target : goal)
  {
    if (firstIndex < cards1.size() && cards1[firstIndex] == target)
    {
      firstIndex++;
    }
    else if (secondIndex < cards2.size() && cards2[secondIndex] == target)
    {
      secondIndex++;
    }
    else
    {
      return "No";
    }
  }
    return "Yes";
}
