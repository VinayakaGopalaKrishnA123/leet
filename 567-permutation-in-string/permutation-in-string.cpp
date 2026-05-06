class Solution {
public:
    bool f(vector<int> &v,vector<int> &vv){
        for(int i=0;i<26;i++){
            if(v[i]!=vv[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> v(26,0);
        vector<int> vv(26,0);
        int n=s1.size();
        for(int i=0;i<n;i++){
            v[s2[i]-'a']++;
            vv[s1[i]-'a']++;
        }
        if(f(v,vv)) return true;
        for(int i=n;i<s2.size();i++){
            v[s2[i]-'a']++;
            v[s2[i-n]-'a']--;
            if(f(v,vv)) return true;
        }
        return false;
    }
};