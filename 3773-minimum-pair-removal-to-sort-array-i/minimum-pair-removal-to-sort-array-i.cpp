class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(nums.size()>1){
            int f=0;
            int minsum=INT_MAX;
            int ti=-1;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    f=1;
                }
                if(nums[i]+nums[i+1]<minsum){
                    minsum=nums[i]+nums[i+1];
                    ti=i;
                }
            }
            if(f==0) break;
            ans++;
            nums[ti]=minsum;
            nums.erase(nums.begin()+ti+1);
        }
        // for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
        return ans;
    }
};