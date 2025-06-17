vector<int> solution(vector<int> numbers) {
  vector<int> result;
  for (size_t i = 0; i < numbers.size() - 1; i++)
  {
    for (size_t j = i + 1; j < numbers.size(); j++)
    {
        result.push_back(numbers[i] + numbers[j]);
    }
  }
  
  sort(result.begin(), result.end());
  auto last = unique(result.begin(), result.end());
  result.erase(last, result.end());
  
  return result;
}
