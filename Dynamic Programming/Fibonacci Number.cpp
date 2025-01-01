//memoization approach - Top Down

class Solution {
public:
    int f(int n, vector<int> &dp) {
        if (n <= 1){
            return n;
        }

        if (dp[n] != -1) return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        return f(n, dp);
    }
};

//Tabularization approach - Bottom Up
class Solution {
public:
    int fib(int n) {
        int f[n+1];
        if (n == 1 || n == 0) return n;
        f[0] = 0;
        f[1] = 1; 
        for (int i=2; i<=n; i++) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};

class Solution {
public:
    int fib(int n) {
        //space optimization approach - O(n)
        if(n <= 1) return n;
        int prev2 = 0;
        int prev1 = 1;
        int curr = 0;

        for(int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};