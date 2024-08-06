class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int l = 0, r = n - 1;
        int res = 0;

        sort(people.begin(), people.end());

        while(l<=r)
        {
            int remain = limit - people[r];
            r--;
            res++;
            if(l <= r && remain >= people[l])
            {
                l++;
            }

        }

    return res;
        
    }
};