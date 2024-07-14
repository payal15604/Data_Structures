class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int ele_sum = 0, digit_sum = 0; 

        for(int i = 0; i < n; i++)
        {
            ele_sum += nums[i];

            while(nums[i] >= 1)
            {
                digit_sum += nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
        
        
        }
        

        return abs(ele_sum - digit_sum);
    }
};