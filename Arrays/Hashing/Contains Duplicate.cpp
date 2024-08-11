class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> h;
        for(int i = 0; i < nums.size(); i++)
        {
            if(h[nums[i]]==0)
            {
                h[nums[i]]++;
            }

            else
            {
                return true;
            }
        }

        return false;
    }
};