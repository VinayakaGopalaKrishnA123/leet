class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=1;
        int n=nums.size();
        int mans=1;
        for(int i=1;i<n;i++){
            int ans=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) ans=max(ans,dp[j]);
            }
            cout<<ans<<' ';
            dp[i]=ans+1;
            mans=max(mans,ans+1);
        }
        return mans;
    }
};