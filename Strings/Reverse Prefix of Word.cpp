class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, j = 0;

        while(j < word.size())
        {
            if(word[j]==ch)
            {
                reverse(word.begin(), word.begin()+j+1);
                break;
            }
            j++;
        }

        return word;

    }
};