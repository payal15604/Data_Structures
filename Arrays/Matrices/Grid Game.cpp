class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size();
        long long res = LLONG_MAX;
        vector<long long> prefrow1(n); 
        vector<long long> prefrow2(n);

        // Compute prefix sums for both rows
        prefrow1[0] = grid[0][0];
        prefrow2[0] = grid[1][0];
        
        for(int i = 1; i < n; i++) {
            prefrow1[i] = prefrow1[i-1] + grid[0][i];
            prefrow2[i] = prefrow2[i-1] + grid[1][i];
        }

        for(int i = 0; i < n; i++) {
            long long bottomrow = (i > 0) ? prefrow2[i-1] : 0;
            long long toprow = prefrow1[n-1] - prefrow1[i];
            long long secondrobot = max(toprow, bottomrow);
            res = min(res, secondrobot);
        }

        return res;
    }
};
