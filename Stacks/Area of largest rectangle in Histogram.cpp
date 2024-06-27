class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int rightsmallest[n], leftsmallest[n];

        //left smallest
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                leftsmallest[i] = 0;
            }

            else
            {
                leftsmallest[i] = st.top() + 1;
            }

            st.push(i);
        }

        //empty stack again

        while(!st.empty())
        {
            st.pop();
        }

        //rightsmallest

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                rightsmallest[i] = n - 1;

            }

            else{
                rightsmallest[i] = st.top() - 1;
            }

            st.push(i);
        }

        //answer for area


        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i] * (rightsmallest[i] - leftsmallest[i] + 1));
        }

        return maxArea;


    }
};