class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=0,l=1;
        for(int i=0;i<piles.size();i++){
            r=max(r,piles[i]);
        }
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            long long th=0;
            for(int i=0;i<piles.size();i++){
                // cout<<ceil((piles[i]*1.0)/mid)<<' ';
                th+=ceil((piles[i]*1.0)/mid);
            }
            if(th<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
            // cout<<th<<" "<<mid<<'\n';
        }
        return ans;
    }
};