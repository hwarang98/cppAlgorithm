#include <bits/stdc++.h>

using namespace std;

string word;

bool isVowels(char c)
{
	return string("aeiou").find(c) != string::npos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> word;
		
		if (word == "end") break;
		
		int vowelsCount = 0; // 모음 등장횟수
		int consonantsCount = 0; // 자음 등장횟수
		int sameWordCount = 0; // 같은 문자 등장 횟수
		bool flag = false; 
		bool includeVowel = false; // 모음 포함 flag
		
		for (size_t i = 0; i < word.length(); i++)
		{
			const char c = word[i];
			
			// 현재 c 가 자음 이라면
			if (isVowels(c))
			{
				vowelsCount++;
				consonantsCount = 0;
				includeVowel = true;
			}
			// 현재 c 가 모음 이라면
			else
			{
				consonantsCount++;
				vowelsCount = 0;
			}
			
			// 모음 이나 자음이 3개 이상 이면 flag = true
			if (vowelsCount >= 3 || consonantsCount >= 3)
			{
				flag = true;
				break;
			}
			
			// 현재 글자와 이전 글자가 동일하다면
			if (i > 0 && word[i] == word[i - 1])
			{
				sameWordCount++;
				
				// ee 또는 oo 는 예외처리
				if (c != 'e' && c != 'o')
				{
					flag = true;
					break;
				}
			}
			else
			{
				sameWordCount = 0;
			}
			
		}
		
		// 모음이 최소 1개를 포함한다면
		if (!includeVowel) flag = true;
		
		if (flag) cout << "<" << word << ">" << " is not acceptable." << "\n";
		else cout << "<" << word << ">" << " is acceptable." << "\n";
	}
	return 0;
}