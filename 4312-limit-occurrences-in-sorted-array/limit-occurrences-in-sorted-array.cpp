class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int count =1;
        int pv=nums[0];
        ans.push_back(pv);
        int i;
        for( i=1;i<nums.size();i++){
            if(nums[i]!=pv){
                count=0;
            }
            count++;
            if(count<=k) ans.push_back(nums[i]);
            pv=nums[i];
        }
        return ans;
    }
};