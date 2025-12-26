#include <bits/stdc++.h>

using namespace std;

int H, W;
string word;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> H >> W;

	for (int i = 0; i < H; ++i)
	{
		cin >> word;
		
		int last_cloud = -1;
		
		for (int j = 0; j < W; ++j)
		{
			if (word[j] == 'c')
			{
				cout << 0 << " ";
				last_cloud = j;
			}
			else
			{
				if (last_cloud == -1)
				{
					cout << -1 << " ";
				}
				else
				{
					cout << j - last_cloud << " ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}