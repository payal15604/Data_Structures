class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0;
        int n = nums.size();
        int odd = 0;

        while (j < n) {
            if (nums[j] % 2 != 0) {
                odd++;
            }

            while (odd > k) {
                if (nums[i] % 2 != 0) {
                    odd--;
                }
                i++;
            }

            count += j - i + 1; // Count subarrays with at most k odd numbers
            j++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
