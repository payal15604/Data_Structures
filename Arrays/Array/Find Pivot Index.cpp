class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(n,0);
        vector<int> right_sum(n,0);

        if(n==1) {return 0;}

        for(int i = 1; i < n; i++)
        {
            left_sum[i] = left_sum[i-1] + nums[i-1];
        }

        for(int i = n - 2; i >= 0; i--)
        {
            right_sum[i] = right_sum[i+1] + nums[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            if(left_sum[i]==right_sum[i])
            {
                return i;
            }
        }

        return -1;
    

        /*
        int n = nums.size();
        if(n==1) {return 0;}

        for(int i = 0; i < n; i++)
        {
            int sum_left = 0;
            int sum_right = 0;
            for(int j = 0; j < i ; j++)
            {
                sum_left +=nums[j];
            }

            for(int j = i+1; j < n; j++)
            {
                sum_right +=nums[j];
            }

            if(sum_left == sum_right)
            {
                return i;
            }
        }


        return -1;
        */
    }
};