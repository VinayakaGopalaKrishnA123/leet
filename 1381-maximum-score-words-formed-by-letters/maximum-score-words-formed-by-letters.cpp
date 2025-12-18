class Solution {
public:
    int ma=INT_MIN;
    void f(int i,vector<string>&w,vector<char>&l,vector<int>&s,unordered_map<char,int> m,int ta){
        if(i>=w.size()) {
            ma=max(ma,ta);
            return;
        }
        int fl=1;
        unordered_map<char,int> sm=m;
        for(int j=0;j<w[i].size();j++){
            sm[w[i][j]]--;
            if(sm[w[i][j]]<0) {
                fl=0;
            }
        }
        cout<<fl;
        if(fl==1){
            int tta=0; 
            for(int j=0;j<w[i].size();j++){
                tta+=s[w[i][j]-'a'];
            }
            f(i+1,w,l,s,sm,ta+tta);
        }
        f(i+1,w,l,s,m,ta);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>m;
        for(auto i: letters) m[i]++;
        // for(int i=1;i<=words.size();i++){
            f(0,words,letters,score,m,0);
        // }
        return ma;
    }
};