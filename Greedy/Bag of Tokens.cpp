class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, res = 0, r = tokens.size() - 1, l = 0;
        sort(tokens.begin(), tokens.end());

        while(l<=r)
        {
            if(power >= tokens[l])
            {
                power -= tokens[l];
                score++;
                l++;
                res = max(res, score);
            }

            else if(score > 0)
            {
                power += tokens[r];
                score--;
                r--;

            }

            else
            {
                break;
            }

            
        }

        return res;
    }
};