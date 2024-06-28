class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans;
        
        for (char c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        // Remove remaining k digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Construct the result string from the stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        
        ans = ans.substr(i);
        
        // If ans is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};
