class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i = 0;
    StockSpanner() {}

    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int greatestIndex = st.empty() ? -1 : st.top().second;
        int ans = i - greatestIndex;
        st.push({price, i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */