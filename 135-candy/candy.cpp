class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> v(ratings.size());
        v[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                v[i]=v[i-1]+1;
            }
            else{
                v[i]=1;
            }
            // cout<<v[i]<<' ';
        }
        // cout<<'\n';
        int sum=v[ratings.size()-1];
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && v[i]<=v[i+1]){
                v[i]=v[i+1]+1;
            }
            
            sum+=v[i];
        }
        for(auto i:v) cout<<i<<' ';
        // 1 2 1 0 3
        // 1 2 1 1 2
        // 1 3 2 1
        // 1 0 3 2
        // 2 1 2 1
        // 1 3 2 0
        // 1 2 1 1
        // 1 3 2 1   
        // 1 2 87 87 87 2 1
        // 1 2 3  1  3  2 1             
        return sum;
    }
};