class Solution {
public:
    string f(string c){
        string t="";
        for(int i=c.size()-1;i>=0;i--){
            t+=c[i];
        }
        return t;
    }
    string reverseWords(string s) {
        unordered_map<int,int> m;
        int vc=0;
        string ts="";
        string ans="";
        int j=0;
        int fvc=0;
        while(j<s.size() && s[j]!=' '){
            ans+=s[j];
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') fvc++;
            j++;
        }
        if(j!=s.size()) ans+=' ';
        for(int i=j+1;i<s.size();i++){
            if(s[i]==' '){
                if(vc==fvc ){
                    ans+=f(ts);
                    ans+=' ';
                }
                else{
                    ans+=ts;
                    ans+=' ';
                }
                ts="";
                vc=0;
            }
            else{
                ts+=s[i];
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') vc++;
            }
        }
        if(vc==fvc){
            ans+=f(ts);
            m[vc]=0;
        }
        else{
            ans+=ts;
            m[vc]++;
        }
        return ans;
    }
};