class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int n = s.size(), i = 0, j = 0;
        int maxlen = 0;

        while(j < n) {
            // If we encounter a repeated character, move the start pointer i
            if(hash[s[j]] > 0) {
                hash[s[i]]--; // Reduce the count of the character at position i
                i++;
            } else {
                // Otherwise, expand the window by including s[j]
                hash[s[j]]++;
                maxlen = max(maxlen, j - i + 1);
                j++;
            }
        }

        return maxlen;
    }
};
