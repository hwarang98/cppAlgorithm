#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
  string left = "";

  for (size_t i = 0; i < food.size(); i++)
  {
    int eatCount = food[i] / 2;
    left += string(eatCount, '0' + i);
    
  }
  
  string right = left;
  reverse(right.begin(), right.end());
  string result = left + "0" + right;


  return result;
}
