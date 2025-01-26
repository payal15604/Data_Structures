class Solution {
public:
    int rows, cols;

    void dfs(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
            return;

        grid[r][c] = '0';  // Mark as visited
        dfs(r - 1, c, grid); // Explore up
        dfs(r + 1, c, grid); // Explore down
        dfs(r, c - 1, grid); // Explore left
        dfs(r, c + 1, grid); // Explore right
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {  // Found a new island
                    islands++;
                    dfs(row, col, grid);  // Mark the entire island as visited
                }
            }
        }

        return islands;
    }
};
