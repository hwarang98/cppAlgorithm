#include <bits/stdc++.h>

using namespace std;

string word;

// 모음 판독기
bool isVowel(char c)
{
	return string("aeiou").find(c) != string::npos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력받은 문자열을 하나씩 반복
	// 모음 count >= 3, 자음 cnt >= 3 이면 false;
	while (true)
	{
		cin >> word;
		if (word == "end") break;
		
		int vowelCount = 0;      // 모음 등장 횟수
		int consonantsCount = 0; // 자음 등장 횟수
		int sameWordCount = 0;   // 동일한 글자 등장 횟수
		bool flag = false;       // true면 not acceptable
		bool hasVowel = false;   // 모음 포함 여부 (필요해서 추가)
		
		for (size_t i = 0; i < word.size(); i++)
		{
			char c = word[i];
			
			// 현재 글자가 모음이면
			if (isVowel(c))
			{
				vowelCount++;        // 모음 등장 횟수 추가
				consonantsCount = 0; // 자음 등장횟수 초기화
				hasVowel = true;     // 모음 포함 여부 true
			}
			else
			{
				consonantsCount++;
				vowelCount = 0;
			}
			
			if (vowelCount >= 3 || consonantsCount >= 3)
			{
				flag = true;
				break;
			}
			
			// 같은 글자인지 체크
			if (i > 0 && word[i] == word[i - 1])
			{
				sameWordCount++;
				
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
		
		// 모음이 최소 1개가 포함되어있는지
		if (!hasVowel) flag = true;
		
		if (flag) cout << "<" << word << ">" << " is not acceptable." << "\n";
		else cout << "<" << word << ">" << " is acceptable." << "\n";
	}
	
	return 0;
}