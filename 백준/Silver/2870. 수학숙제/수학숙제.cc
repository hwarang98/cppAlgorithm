#include <bits/stdc++.h>

using namespace std;

int n;
string word;
vector<string> nums;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	while (n--)
	{
		string s;
		cin >> s;
		
		string current;
		
		for (const char &c : s)
		{
			if (isdigit(c))
			{
				current.push_back(c);
			}
			else
			{
				if (!current.empty())
				{
					int pos = 0;

					while (pos + 1 < current.size() && current[pos] == '0') pos++;
					nums.push_back(current.substr(pos));
					current.clear();
				}
			}
		}
		
		if (!current.empty())
		{
			int pos = 0;
			while (pos + 1 < current.size() && current[pos] == '0') pos++;
			nums.push_back(current.substr(pos));
		}
	}
	
	sort(nums.begin(), nums.end(), [](const string &a, const string &b)
	{
		if (a.size() != b.size()) return a.size() < b.size();
		return a < b;
	});
	
	
	for (const string &num : nums) cout << num << '\n';
	
	return 0;
}