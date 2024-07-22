class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = points.size();
        vector<int> answer(n, 0);

        // Iterate through each query
        for (int i = 0; i < n; i++) {
            int count = 0;
            int x_centre = queries[i][0];
            int y_centre = queries[i][1];
            int radius = queries[i][2];
            int radius_squared = radius * radius; // Precompute the squared radius

            // Iterate through each point
            for (int j = 0; j < m; j++) {
                int x = points[j][0];
                int y = points[j][1];

                // Calculate the squared distance and compare with the squared radius
                int dx = x_centre - x;
                int dy = y_centre - y;
                if (dx * dx + dy * dy <= radius_squared) {
                    count++;
                }
            }

            answer[i] = count; // Update the count for the current query
        }

        return answer;
    }
};
