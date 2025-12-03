class Solution {
public:
    int bsearch(vector<int>& v,int x){
        int l=0,r=v.size()-1,ans=v.size();
        while(l<=r){
            int m=(l+r)/2;
            if(v[m]>x){ ans=m; r=m-1; }
            else l=m+1;
        }
        return ans;
    }
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int j=bsearch(nums,nums[i]);
            cout<<j<<"\n";
            if((nums.size()-j)>=k) cnt++;
        }
        return cnt;
    }
};