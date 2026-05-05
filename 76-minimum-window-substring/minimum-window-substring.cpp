class Solution {
public:
    int f(vector<int> &cf,vector<int>&tcf){
        for(int i=0;i<58;i++){
            if(cf[i]>tcf[i]) return 0;
        }
        return 1;
    }
    string minWindow(string s, string t) {
        vector<int> cf(58,0);
        vector<int> tcf(58,0);
        string ans="";
        for(int i=0;i<t.size();i++){
            cf[t[i]-'A']++;
        }
        int l=0,r=0;
        
        int ml=0,mr=INT_MAX;
        while(r<s.size()){
           
                tcf[s[r]-'A']++;
                r++;
            
           
            while(f(cf,tcf) ){
                tcf[s[l]-'A']--;
                if(mr-ml > r-l){
                    mr=r;
                    ml=l;
                }
                l++;
                
            }
            
        }
        if(mr==INT_MAX) return "";
        for(int i=ml;i<mr;i++) ans+=s[i];
        // cout<<ans;
        return ans;
    }
};