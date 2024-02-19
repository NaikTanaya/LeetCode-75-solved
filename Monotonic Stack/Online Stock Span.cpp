class StockSpanner {
public:
    stack<pair<int, int>> st; // stack of pair--> first = price && second = span...
    StockSpanner() {
    }
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){ // Check previous price <= current price...
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

// Example 1:

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
// stockSpanner.next(85);  // return 6
