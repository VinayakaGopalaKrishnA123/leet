class Solution {
public:
    int numSteps(string s) {
        int c=0;
        while(s!="1"){
            c++;
            if(s[s.size()-1]=='1'){
                int i=s.size()-1;
                while (i>=0&&s[i]=='1') {
                    s[i] = '0';
                    i--;
                }
                if (i>=0) {
                    s[i]='1';
                } 
                else {
                    s="1"+s;  
                }
            }
            else{
                s.pop_back();
            }
        }
        return c;
    }
};