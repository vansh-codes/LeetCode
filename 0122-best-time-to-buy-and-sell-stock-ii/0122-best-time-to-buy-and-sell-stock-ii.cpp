class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size()<=1) return 0;
        int buy = 0, sell = -1;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                sell = i;
            } else{
                if(sell!=-1){
                    profit += (prices[sell]-prices[buy]);
                }
                buy = i;
                sell = -1;
            }
        }
        if(sell!=-1){
            profit+= (prices[sell] - prices[buy]);
        }
        return profit;
    }
};