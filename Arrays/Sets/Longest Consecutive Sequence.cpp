class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> nums_set(nums.begin(), nums.end()); // Store all elements in a set for O(1) average time complexity access

        for(auto &x : nums)
        {
            if(!nums_set.count(x-1)) // If x-1 is not in the set, x is the start of a sequence
            {
                int length = 0;
                while(nums_set.count(x+length)) // Count the length of consecutive numbers starting from x
                {
                    ++length;
                }

                longest = max(longest, length); // Update the longest sequence found
            }
        }
        return longest;
    }
};
