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

//TLE giving with new approach

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;

        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = true;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(map.count(nums[i]-1)>0)
            {
                map[nums[i]] = false;
            }
        }

        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map[nums[i]] == true){
                int j = 0; int count = 0;
                while(map.count(nums[i] + j) > 0)
                {
                    j++;
                    count++;
                } 

                maxlen = max(maxlen, count);
            }
        }

         return maxlen;
    }

  
};
