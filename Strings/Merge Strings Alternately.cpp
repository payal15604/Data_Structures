class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        int n = word1.size();
        int m = word2.size();

        // Merge characters alternately
        while (i < n && j < m) {
            result += word1[i++];
            result += word2[j++];
        }

        // Append remaining characters from word1
        while (i < n) {
            result += word1[i++];
        }

        // Append remaining characters from word2
        while (j < m) {
            result += word2[j++];
        }

        return result;
    }
};
