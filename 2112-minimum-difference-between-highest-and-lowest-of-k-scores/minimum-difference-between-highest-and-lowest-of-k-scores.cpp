class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans=nums[nums.size()-1]-nums[nums.size()-k];
        for(int i=nums.size()-1;i>=k-1;i--){
            ans=min(ans,nums[i]-nums[i+1-k]);
        }
       return ans;
    }
};