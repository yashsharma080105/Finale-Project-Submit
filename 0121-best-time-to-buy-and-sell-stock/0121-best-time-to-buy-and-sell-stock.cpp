class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyprice = prices[0];
        int profit   =0 ;
        for(int i=1;i<n;i++){
            if(buyprice > prices[i]){
                buyprice[i] = prices[i];
            }
            profit = max(profit,prices[i]-buyprice[i]);
        }
        return profit;
        
    }
};