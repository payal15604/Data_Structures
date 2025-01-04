class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            --i;
        }

        // Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            ++len;
            --i;
        }

        return len;
    }
};
