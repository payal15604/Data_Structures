class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n - 1, temp = 0;

        while(i<j)
        {
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            i++; j--;

        }
    }
};