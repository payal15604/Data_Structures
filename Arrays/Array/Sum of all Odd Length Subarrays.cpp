class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        //optimised
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; ++i)
        {
            int num_of_subarrays = (n - i) * (i + 1);
            sum += ((num_of_subarrays + 1)/2) * nums[i];
        }


        return sum;
      /* brute force
      
      int sum=0;
    
     for(int i=1;i<=nums.size();i=i+2)
      {
       for(int j=0;j+i<=nums.size();j++)
       {
        for(int k=j;k<j+i;k++)
        {
            sum=sum+nums[k];
        }
       }
      }
    return sum;*/
    }
};