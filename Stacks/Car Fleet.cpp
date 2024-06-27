#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> fleet;
        stack<double> st;

        // Fill fleet with positions and speeds
        for(int i = 0; i < position.size(); i++) {
            fleet.push_back({position[i], speed[i]});
        }

        // Sort fleet based on position (ascending)
        sort(fleet.begin(), fleet.end());

        // Calculate time to reach target and simulate car fleets
        for(int i = 0; i < fleet.size(); i++) {
            double time = (double)(target - fleet[i].first) / fleet[i].second;

            // Check if current car can form a new fleet or merge with previous
            while(!st.empty() && st.top() <= time) {
                st.pop(); // Merge with previous fleet
            }

            st.push(time); // Form new fleet with current car
        }

        return st.size(); // Number of fleets formed
    }
};
