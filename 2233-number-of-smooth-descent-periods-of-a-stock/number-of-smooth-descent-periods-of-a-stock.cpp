class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        vector<int> v;
        int n=p.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(p[i-1]-p[i]==1){
                c++;
            }
            else{
                v.push_back(c+1);
                c=0;
            }
        }
        v.push_back(c+1);
        long long ans=0;
        for(auto i:v){
            // cout<<i<<' ';
            ans+=((i*1ll*(i-1))/2);
        }
        
        return ans+n;
    }
};