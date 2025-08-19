class Solution {
public:
    int cols, rows;

    int dfs(int r, int c, vector<vector<int>> &grid){
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int area = 1;
        area += dfs(r-1, c, grid);
        area += dfs(r+1, c, grid);
        area += dfs(r, c-1, grid);
        area += dfs(r, c+1, grid);

        return area;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        int maxArea = 0;

        

        for(int row= 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col]==1)
                {
                    maxArea = max(maxArea,dfs(row, col, grid));
                }
            }
        }

        return maxArea;
    }
};