class Solution {
public:
    string arrangeWords(string text) {
        vector<vector<string>> bu(100000);
        string s="";
        int ml=0;
        for(char c:text){
            if(c==' '){
                bu[s.size()].push_back(s);
                ml=max(ml,(int)s.size());
                s="";
            } else s+=tolower(c);
        }
        bu[s.size()].push_back(s);
        ml=max(ml,(int)s.size());
        string ans="";
        bool first=true;
        for(int len=1;len<=ml;len++){
            for(string w:bu[len]){
                if(first){
                    w[0]=toupper(w[0]);
                    ans+=w;
                    first=false;
                } else {
                    ans+=' ';
                    ans+=w;
                }
            }
        }
        return ans;
    }
};
