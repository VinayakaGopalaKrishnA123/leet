class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        cout<<(1|2);
        for(int i=0;i<nums.size();i++){
            int temp=-1;
            for(int j=1;j<=1000;j++){
                if((j|j+1)==nums[i]){ temp=j;break;}
            }
            ans[i]=temp;
        }
        return ans;
    }
};