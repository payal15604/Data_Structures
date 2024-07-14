class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        //optimised
        int n = mat.size();
        int mid = n / 2;
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += mat[i][i] + mat[i][n-i-1];
        }

        if(n%2 == 1)
        {
            sum -= mat[mid][mid];
        }

        return sum;
        /*
        int col = mat.size();
        int row = mat[0].size();
        int sum = 0;

        for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
            {
                if(i == j || i+j == (row-1)) {sum+=mat[i][j];}
            }
        }

        return sum;
        */
        
    }
};