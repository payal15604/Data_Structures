class Solution {
public:
//two pointer approach
    bool isSubsequence(string s, string t) {
        int sp = 0;
        int tp = 0;

        while(sp != s.size() && tp != t.size())
        {
            if (s[sp] == t[tp])
            {
                sp++;
            }

            tp++;
        }

        if(sp == s.size())
        {
            return true;
        }

        return false;
    }
};