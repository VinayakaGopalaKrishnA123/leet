class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=nums[0];
        int minl=INT_MAX;
        while(j<nums.size()){
            if(sum>=target){
                minl=min(minl,j-i+1);
                i++;
                sum-=nums[i-1];
            }
            else if(sum<target){
                j++;
                if(j>=nums.size()) break;
                else sum+=nums[j];
            }
        }
        if(minl==INT_MAX) return 0;
        return minl;
    }
};