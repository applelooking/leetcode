class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy = INT_MAX;
        for (auto price : prices) {
            if (price < buy) buy = price;
            else result = max(result, price - buy);
        }
        return result;
    }
};