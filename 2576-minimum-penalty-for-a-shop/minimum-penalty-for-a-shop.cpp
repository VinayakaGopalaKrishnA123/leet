class Solution {
public:
    int bestClosingTime(string customers) {
        int cn=0;
        int cy=0;
        for(auto j:customers) if(j=='Y') cy++;
        int ans=INT_MAX;
        int ansi=0;
        int i;
        for(i=0;i<customers.size();i++){
            if(cy+cn<ans){
                ansi=i;
                ans=min(ans,cy+cn);
            }
            // cout<<cn<<' '<<cy<<"\n";
            if(customers[i]=='Y') cy--;
            else if(customers[i]=='N') cn++;
        }
        if(cy+cn<ans){
            ansi=i;
            ans=min(ans,cy+cn);
        }
        return ansi;
    }
};