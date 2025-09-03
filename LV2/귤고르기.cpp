#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
unordered_map<int, int> freq; for (int x : tangerine) ++freq[x];


vector<int> counts;
counts.reserve(freq.size());
for (const auto& kv : freq) {
    counts.push_back(kv.second);
}

sort(counts.begin(), counts.end(), greater<int>());

int kinds = 0;
for (int c : counts) {
    if (k <= 0) break;
    k -= c;
    ++kinds;
}
return kinds;
}
