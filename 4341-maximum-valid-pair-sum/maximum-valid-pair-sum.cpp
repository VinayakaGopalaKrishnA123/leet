class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int> v(n);
       v[n-1]=nums[n-1];
       for(int j=n-2;j>=0;j--){
            v[j]=max(nums[j],v[j+1]);
       }
       int tans=nums[0]+nums[n-1];
       for(int i=0;i<n-k;i++){
            // cout<<nums[i]+v[i+k]<<'\n';
            tans=max(tans, nums[i]+v[i+k]);
       }
       return tans;

    }
};