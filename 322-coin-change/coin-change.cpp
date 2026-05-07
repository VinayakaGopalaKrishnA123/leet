class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        sort(coins.begin(),coins.end());
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int ans=INT_MAX;
            for(auto j:coins){
                if(j>i) break;
                if(dp[i-j]!=INT_MAX) ans=min(ans,dp[i-j]+1);
            }
            dp[i]=ans;
        }
        // for(auto i:dp) cout<<i<<' ';
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};