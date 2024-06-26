#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // Use pair<int, int> to store price and span

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        // Pop elements from the stack whose prices are less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the popped element to the current span
            st.pop();
        }

        // Push the current price and its span onto the stack
        st.push({price, span});

        return span;
    }
};
