class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size(),ans=0;
        int purchase =-1;
        for(int i=0;i<n;i++)
        {
            if(purchase==-1 || prices[i]<purchase)
            {
                purchase = prices[i];
            }
            else if(prices[i]>purchase)
            {
                ans=max(ans,prices[i]-purchase);
            }
        }
        return ans;
    }
};
