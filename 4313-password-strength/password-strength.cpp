class Solution {
public:
    int passwordStrength(string password) {
        int sc=0;
        unordered_map<char,int> m;
        for(auto i:password){
            if(i>='a' && i<='z' && m[i]==0) sc++;
            else if(i>='A' && i<='Z' && m[i]==0) sc+=2;
            else if(i>='0' && i<='9' && m[i]==0) sc+=3;
            else if((i=='!' || i=='@' || i=='#' || i=='$' ) && m[i]==0) sc+=5;
            // cout<<sc<<' ';
            m[i]++;
        }
        return sc;
    }
};