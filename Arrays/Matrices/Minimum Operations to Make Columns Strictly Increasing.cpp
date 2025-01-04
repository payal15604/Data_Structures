class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int greatest = -1;
        int count = 0;

        for(int j = 0; j < col; j++)
            {
               for(int i = 1; i < rows; i++)
                   {
                       int prev = grid[i-1][j];
                       if(grid[i-1][j] >= grid[i][j]) 
                       {
                        count += abs(prev - grid[i][j] + 1);
                        grid[i][j] = prev + 1;}
                   }
                
            }


        return count;
    }
};