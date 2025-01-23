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

//approach 2 with neater code

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>map;

        for(int num : nums) //populate the map
        {
            map[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &[num, freq]: map) //fill in the bucket
        {
            bucket[freq].emplace_back(num);
        }

        vector<int> ans;

        for(int i = bucket.size() - 1; i > 0 && k>0; i--)
        {
            for(int num : bucket[i])
            {
                ans.emplace_back(num);
                k--;

                if(k == 0) break;
            }

            
        }

        return ans;
    }
};