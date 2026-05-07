class Solution {
public:
    int minCost(int n) {
        vector<int> dp(n+1);
        dp[1]=0;
        for(int i=2;i<=n;i++){
            int k=i/2;
            int ans=INT_MAX;
            for(int j=1;j<=k;j++){
                ans=min(ans,dp[k]+dp[i-k]+(k*(i-k)));
            }
            dp[i]=ans;
            // cout<<dp[i]<<' ';

        }
        return dp[n];
    }
};