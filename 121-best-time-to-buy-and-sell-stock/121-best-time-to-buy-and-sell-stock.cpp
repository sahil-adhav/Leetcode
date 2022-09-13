class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxValue = 0;
        
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxValue = max(maxValue, prices[i] - minPrice);
        }
        return maxValue;
    }
};