class Solution {
public:
    int numberOfSubstrings(string s) {
        int right = 0, left = 0, count = 0;
        int n = s.size();
        map<char, int> hash;

        while(right < n)
        {
            hash[s[right]]++;
            while (hash['a'] && hash['b'] && hash['c'])
            {
                count += n - right;
                hash[s[left]]--;
                left++;
            }
            right++;

        }

        return count;
        
    }
};