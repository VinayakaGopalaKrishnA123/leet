class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        // 1 3 6 10 15 21
        // 1 2 3 4 5 6 1 2 3 4 5 6
        // 0 1 2 3 4 5 6 7 8 9 10 11
        vector<int> te=nums;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            te.push_back(nums[i]);
        }
        vector<long long> ps(te.size());
        ps[0]=te[0];
        for(int i=1;i<ps.size();i++){
            ps[i]=ps[i-1]+te[i];
        }
        int ans=0;
        for(int j=n-1;j<2*n-1;j++){
            int i=j-(n-1);
            int m= (i+j)/2;
            int ls=ps[m],rs=ps[j]-ps[m];
            if(i!=0) ls-=ps[i-1];
            if(ls>rs) ans++;
        }
        return ans;
    }
};