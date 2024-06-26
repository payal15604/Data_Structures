class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        //vector<int> ans;

        for(int i = 0; i < asteroids.size(); i++)
        {
            int curr = asteroids[i];
            bool destroyed = false;

            while(!st.empty() && curr < 0 && st.top() > 0)
            {
                int topele = st.top();
                if(abs(topele)==abs(curr))
                {
                    st.pop();
                    destroyed = true;
                    break;
                }

                else if(abs(topele) < abs(curr))
                {
                    st.pop();
                }

                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed)
            {
                st.push(curr);
            }

        }
        vector<int> ans(st.size());
        for(int i = st.size() -1 ; i >=0; --i)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};