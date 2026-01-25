class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int in=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                in=i;
                break;
            }
        }
        if(in==-1) return 0; 
        
        return in+1;
    }
};