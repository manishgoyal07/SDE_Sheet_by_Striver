int maximumProfit(vector<int> &prices){
    int profit=INT_MIN, mini=prices[0];
    int n=prices.size();
    for(int i=1; i<n; i++){
        mini=min(mini, prices[i]);
        profit = max(profit, prices[i]-mini);
    }
 return profit;
}