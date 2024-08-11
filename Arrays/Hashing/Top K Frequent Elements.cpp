class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();

        for(auto x : nums)
        {
            map[x]++;
        }

        vector<vector<int>> bucket(n+1);
        for(auto it = map.begin(); it != map.end(); it++)
        {
            bucket[it->second].push_back(it->first);
        }

        vector<int> res;

        for (int i = n; i >= 0; i--) {
            if (res.size() >= k) {
                break;
            }
            if (!bucket[i].empty()) {
                res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        return res;
    }
};