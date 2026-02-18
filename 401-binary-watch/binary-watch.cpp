class Solution {
public:
    void f(vector<string>&b,int n,int c,int lc,string s){
        if(lc==10) {
            if(c==n)b.push_back(s);
            return ;
        }
        if(c<n) f(b,n,c+1,lc+1,s+"1");
        f(b,n,c,lc+1,s+"0");
    }
    string ff(string ii){
        int  h=0;
        int  m=0;
        int j=0;
        for(int i=0;i<4;i++){
            if(ii[i]=='1')h+=pow(2,j);
            j++;
        }
        j=0;
        for(int i=4;i<10;i++){
            if(ii[i]=='1')m+=pow(2,j);
            j++;
        }
         if(h>=12 || m>=60) return "";

        string mm = (m<10 ? "0"+to_string(m) : to_string(m));
        return to_string(h) + ":" + mm;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> b;
        vector<string> ans;
        f(b,turnedOn,0,0,"");
        for(auto i:b){
            string temp=ff(i);
            if(temp!="") ans.push_back(temp);
        }
        return ans;
    }
};