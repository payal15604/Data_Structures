class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash(26);
        int res = 0;
        int l = 0, r = 0;
        int maxfreq = 0;

        for(r = 0; r < s.size(); r++)
        {
            hash[s[r]]++;
            maxfreq = max(maxfreq, hash[s[r]]);
            while(r - l + 1 - maxfreq > k){
            hash[s[l]]--;
            l++;
            
            }

            res = max(res, r - l + 1);
        }

        return res;
       
    }
};