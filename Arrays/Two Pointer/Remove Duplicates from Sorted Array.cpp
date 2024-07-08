class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;
        //two pointer method
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        
        for(int right = 1; right < nums.size(); right++)
        {
            if(nums[right-1]!=nums[right])
            {
                nums[left++] = nums[right];
            }
            
    
        }

        return left;
    }
};