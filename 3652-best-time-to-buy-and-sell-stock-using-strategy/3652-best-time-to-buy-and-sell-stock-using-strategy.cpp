class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long tot = 0, ans = 0;
        for (int i = 0; i < prices.size(); i++){
            tot += prices[i] * strategy[i];
        }  

        ans = tot; 

        long long modifi = 0, org = 0;
        for (int i = 0; i < prices.size(); i++){
            org += prices[i] * strategy[i];
            if (i >= k / 2) modifi += prices[i];

            if (i + 1 >= k){
                ans = max(ans, tot - org + modifi);
                org -= prices[i - k + 1] * strategy[i - k + 1];
                modifi -= prices[i - k / 2 + 1];
            }
        }

        return ans;
    }
};