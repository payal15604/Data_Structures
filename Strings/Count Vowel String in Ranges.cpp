class Solution {
public:
//prefix sum
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
        else return 0;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i+1] = prefix[i];
            int l = words[i].length();
            if(isVowel(words[i][0]) && isVowel(words[i][l-1])) prefix[i+1]++;

        }

        int m = queries.size();
        vector<int> ans(m,0);
        for(int i = 0; i < m; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            ans[i] = prefix[r+1] - prefix[l]; 

        }


        return ans;

    }
};