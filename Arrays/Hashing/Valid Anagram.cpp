class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) 
        {return false;}
        unordered_map<char, int> h1;

        for(auto x : s)
        {
            h1[x]++;
        }

        for(auto x : t)
        {
            h1[x]--;
        }

        for(auto x : h1)
        {
            if(x.second != 0)
            {
                return false;
            }
        }

        return true;
    }

};