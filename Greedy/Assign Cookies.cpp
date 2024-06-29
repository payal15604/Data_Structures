#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int p1 = 0, p2 = 0, cnt = 0;

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end()); 
        

        while((p1 < g.size()) && (p2 < s.size()))
        {
            if(s[p2] >= g[p1])
            {
                p2++;
                p1++;
                cnt++;
            }

            else
            {
                p2++;
            }
        }

        return cnt;
    }
};