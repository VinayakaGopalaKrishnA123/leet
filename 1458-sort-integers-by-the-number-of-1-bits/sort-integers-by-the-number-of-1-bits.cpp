class Solution {
public:
    int f(int n){
        if(n==0) return 0;
        int c=0;
        while(n>0){
            if(n%2==1) c++;
            n/=2;
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            if(f(a)==f(b)) return a<b;
            return f(a)<f(b);
        });
        return arr;
    }
};