class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rS, int cStart) {
        int n=rows*cols;
        int tn=0;
        int steps=1;
        vector<vector<int>> v;
        v.push_back({rS,cStart});
        int mi=rS,mj=cStart;
        int f=0;
        while(true){
            int i;
            for(i=0;i<steps;i++){
                // cout<<mi<<" "<<i<<"\n";
                mj++;
                if(mi >= 0 && mi < rows && mj >= 0 && mj < cols ){
                    v.push_back({mi,mj});
                }
                if(v.size()==n){
                    f=1;
                    break;
                }
            }
            if(f==1) break;
            for(i=0;i<steps;i++){
                mi++;
                if(mi >= 0 && mi < rows && mj >= 0 && mj < cols){
                    v.push_back({mi,mj});
                }
                if(v.size()==n){
                    f=1;
                    break;
                }
            }
            if(f==1) break;
            steps++;
            for(i=0;i<steps;i++){
                mj--;  
                 if(mi >= 0 && mi < rows &&  mj>= 0 && mj < cols){
                    v.push_back({mi,mj});
                }
                if(v.size()==n){
                    f=1;
                    break;
                }
            }
             if(f==1) break;
            for(int i=0;i<steps;i++){
                mi--;
                if(mi >= 0 && mi < rows && mj >= 0 && mj < cols){
                    v.push_back({mi,mj});
                }
                if(v.size()==n){
                    f=1;
                    break;
                }
            }
             if(f==1) break;
            steps++;
        }
        return v;
    }
};