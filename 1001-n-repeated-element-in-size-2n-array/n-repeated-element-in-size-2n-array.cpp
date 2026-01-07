class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()/2.0;
        if(nums[0]==nums[n-1]) return nums[0];
        return nums[n];
    }
};