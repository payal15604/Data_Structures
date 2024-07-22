class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cols = bank.size();
        int row = bank[0].size();
        vector<int> arr;

        for(int i = 0; i < cols; i++)
        {
            int sum = 0;
            for(int j = 0; j < row; j++)
            {
                sum+= bank[i][j] - '0';
            }
            if(sum){arr.push_back(sum);}
        }
        if(arr.size() < 2) {return 0;}
        int res = 0;
        int prev = arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            res += arr[i] * prev;
            prev = arr[i];
        }

        return res;
    }
};