class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> sf(n);
        sf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sf[i]=sf[i+1]+nums[i];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            // cout<<n-i-1<<' ';
            if(nums[i]>(sf[i+1]/(n-i-1))) cnt++;
        }
        return cnt;
    }
};