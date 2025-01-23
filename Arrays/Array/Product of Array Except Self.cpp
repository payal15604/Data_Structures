class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> left_prod(n,1);
        vector<int> right_prod(n,1);
        vector<int> answer(n,1);

        for(int i = 1; i < n; i++)
        {
            left_prod[i] = left_prod[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--)
        {
            right_prod[i] = right_prod[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            answer[i] = left_prod[i] * right_prod[i];
        }

        return answer;

        /*
        int n = nums.size();
        vector<int> output;
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
        */
    }
};

//neater code 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};