#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int start = 0, max_len = 1;
        
        for (int i = 0; i < s.length(); ++i) {
            // Check odd-length palindromes centered at i
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int curr_len = right - left + 1;
                if (curr_len > max_len) {
                    max_len = curr_len;
                    start = left;
                }
                --left;
                ++right;
            }
            
            // Check even-length palindromes centered between i and i+1
            left = i, right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int curr_len = right - left + 1;
                if (curr_len > max_len) {
                    max_len = curr_len;
                    start = left;
                }
                --left;
                ++right;
            }
        }
        
        return s.substr(start, max_len);
    }
};
