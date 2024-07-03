class Solution {
  public:
    long long solve(vector<int>& bt) {
        long long n = bt.size();
        sort(bt.begin(), bt.end());
        long long t = 0, wt = 0;
        
        for(int i = 0; i < n; i++)
        {
            
            wt += t ;
            t += bt[i];
        }
        
        return wt/n;
    }
};