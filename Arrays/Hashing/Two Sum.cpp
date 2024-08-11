#include <vector>
#include <algorithm> // For std::sort

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(map.count(complement))
            {
                return {map[complement], i};
            }
            map[nums[i]]=i;
        }

        return {};
        /*
        vector<pair<int, int>> numIndex; 
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            numIndex.push_back({nums[i], i});
        }
        
    
        sort(numIndex.begin(), numIndex.end());
        
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = numIndex[i].first + numIndex[j].first;
            if (sum == target) {
                return {numIndex[i].second, numIndex[j].second};
            } else if (sum > target) {
                --j;
            } else {
                ++i;
            }
        }
        
        return {}; 
        */

    }
};
