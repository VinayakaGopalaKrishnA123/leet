class Solution{
public:
    long long minMoves(vector<int>& balance){
        int n=balance.size(),ind=-1;
        long long total=0;
        for(int i=0;i<n;i++){
            total+=balance[i];
            if(balance[i]<0&&ind==-1) ind=i;
        }
        if(total<0) return -1;
        if(ind==-1) return 0;
        long long ans=0,need=-1LL*balance[ind],k=1;
        int i=(ind+k)%n,j=(ind-k+n)%n;
        while(need>0){
            if(balance[i]>0){
                long long take=min((long long)balance[i],need);
                ans+=take*k;
                need-=take;
                balance[i]-=take;
            }
            if(need==0) break;
            if(balance[j]>0){
                long long take=min((long long)balance[j],need);
                ans+=take*k;
                need-=take;
                balance[j]-=take;
            }
            k++;
            i=(ind+k)%n;
            j=(ind-k+n)%n;
        }
        return ans;
    }
};
