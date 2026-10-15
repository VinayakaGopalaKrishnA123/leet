class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int mini=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[i]<nums[mid]){
                mini=min(mini,nums[i]);
                i=mid+1;
            }
            else if(nums[i]==nums[mid] && nums[mid]==nums[j]){
                mini=min(mini,nums[i]);
                i++;
                j--;
            }
            else if(nums[i]==nums[mid] && nums[mid]!=nums[j]){
                mini=min(mini,nums[i]);
                i=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                j=mid-1;
            }
        }
        return mini;
    }
};