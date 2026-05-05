class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int l=0;  
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            l=max(l,weights[i]);
        }
        int ans=sum;
        while(l<=sum){
            int mid=(l+sum)/2;
            int tdays=1;
            int ss=0;
            for(int i=0;i<weights.size();i++){
                ss+=weights[i];
                if(ss>mid){
                    tdays++;
                    ss=weights[i];
                }
            }
            if(tdays<=days){
                sum=mid-1;
                ans=mid;
            }    
            else l=mid+1;
        }
        return ans;
    }
};