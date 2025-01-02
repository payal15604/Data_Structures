class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix_sum(n, -1);
        int greatest = -1;

        for(int i = n-2; i>=0; --i)
        {
            int curr = suffix_sum[i];
            greatest = max(suffix_sum[i+1], arr[i+1]);
            suffix_sum[i] = greatest;
        }

        return suffix_sum;
    }
};