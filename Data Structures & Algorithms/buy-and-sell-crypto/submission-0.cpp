class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> lowest(prices.size());
        vector<int> highest(prices.size());
        int lo = 200;
        for (int i = 0; i<prices.size(); i++){
            if (prices[i]<lo){
                lo=prices[i];
            }
            lowest[i]=lo;
        }
        int hi = -1;
        for (int i = prices.size()-1; i>=0; i--){
            if (prices[i]>hi){
                hi=prices[i];
            }
            highest[i]=hi;
        }

        int best_profit = 0;

        for (int i = 0; i<prices.size(); i++){
            if (best_profit < highest[i]-lowest[i]){
                best_profit = highest[i]-lowest[i];
            }
        }

        return best_profit;
    }
};
