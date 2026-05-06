class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size(),0);
        int i;
        dp[2]=nums[0];
        for(i=3;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i-2],dp[i-3]+nums[i-3]);
        }
        return max(dp[i-1]+nums[i-1],dp[i-2]+nums[i-2]);

    }
};