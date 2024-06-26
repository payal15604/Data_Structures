//sliding window approach

class RecentCounter {
public:
    vector<int> arr;
    int i = 0;
    int j = -1;
    RecentCounter() {
    }
    
    int ping(int t) {
        arr.emplace_back(t);
        j++;
        while(i < j && !arr.empty() && t - 3000 > arr[i]){
            i++;
        }
        return j - i + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */