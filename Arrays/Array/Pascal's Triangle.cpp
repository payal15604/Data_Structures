class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});

        for(int i = 0; i < numRows - 1; i++)
        {
            vector<int> prev_row = res.back();
            prev_row.insert(prev_row.begin(),0);
            prev_row.emplace_back(0);
            vector<int> row;

            for(int j = 0; j < prev_row.size() - 1; j++)
            {
                row.emplace_back(prev_row[j]+prev_row[j+1]);
            }  

            res.emplace_back(row);
        }


        return res;
    }
};