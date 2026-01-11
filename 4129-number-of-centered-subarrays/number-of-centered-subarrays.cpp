class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans=0;
        unordered_map<long long,int> m;
        cout<<nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                m[nums[j]]++;
                if(m[sum]>0) ans++;
            }
            sum=0;
            m.clear();
        }
        return ans;
    }
};