class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Edge cases
        if (n == 0) return -1; // No elements
        if (k == 0) return nums[0]; // No operations, return the top
        if (n == 1) return (k % 2 == 0) ? nums[0] : -1; // One element case

        int max_ele = -1;

        // Consider the first k elements or all elements if n < k
        for (int i = 0; i < min(k-1, n); i++) {
            max_ele = max(max_ele, nums[i]);
        }

        // If k is less than n, we can also consider the k-th element
        if (k < n) {
            max_ele = max(max_ele, nums[k]);
        }

        return max_ele;
    }
};
