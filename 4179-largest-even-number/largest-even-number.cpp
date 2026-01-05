class Solution {
public:
    string largestEven(string s) {
        if((s[s.size()-1]-'0')%2==0) return s;
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]-'0')%2==0){
                temp+=s[i];
            }
            else if(temp!=""){
                temp+=s[i];
            }
        }
        if(temp=="") return "";
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};