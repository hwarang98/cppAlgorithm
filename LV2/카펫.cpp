#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;

    for (int h = 1; h * h <= total; ++h)
    {
        if (total % h != 0) continue;
        int w = total / h; // 12 / 1

        if ((w - 2) * (h - 2) == yellow)
        {
            if (w >= h) return {w, h};
            else return {h, w};
        }
        
    }
    
}
