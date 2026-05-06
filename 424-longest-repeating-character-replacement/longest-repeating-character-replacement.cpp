class Solution {
public:
    int f(vector<int> &cf){
        int sum=0;
        int mans=INT_MIN;
        for(int i=0;i<cf.size();i++){
            mans=max(mans,cf[i]);
            sum+=cf[i];
        }
        return sum-mans;
    }
    int characterReplacement(string s, int k) {
         vector<int> cf(52,0);
        int l=-1,r=0;
        int mans=0;
        while(r<s.size()){
            cf[s[r]-'A']++;
            // cout<<l<<' '<<r<<' '<<mans<<' '<<f(cf)<<'\n';
            while(f(cf)>k){
                l++;
                cf[s[l]-'A']--;
            }
            mans=max(mans,r-l);
            r++;
        }
        return mans;
    }
};