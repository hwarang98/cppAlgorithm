bool isPrime(int n) {
	if (n <= 1) return false;         // 1 이하 숫자는 소수가 아님
	if (n == 2) return true;          // 2는 소수
	if (n % 2 == 0) return false;     // 짝수는 소수가 아님 (2 제외)

	// 홀수로만 나누기 (3부터 √n까지)
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}

	return true;
}


int solution(vector<int> nums) {
	int answer = -1;

	int count = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			for (size_t k = j + 1; k < nums.size(); k++)
			{
				int sum = nums[i] + nums[j] + nums[k];
				if (isPrime(sum))
				{
					cout << sum << endl;
					++count;
				}
			}
		}
	}
	return count;
}
