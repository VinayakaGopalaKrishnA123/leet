class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> dis(mat.size(),vector<int>(mat[0].size(),0)),vis(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){ q.push({i,j}); vis[i][j]=1;}
            }
        }
        int level=0;
        while(!q.empty()){
            int qs=q.size();
            level++;
            for(int i=0;i<qs;i++){
                auto [ti,tj]=q.front();
                q.pop();
                if(ti-1>=0 && vis[ti-1][tj]==0){
                    if(mat[ti-1][tj]==1)  dis[ti-1][tj]=level;
                    q.push({ti-1,tj});
                    vis[ti-1][tj]=1;
                }
                if(ti+1<mat.size() && vis[ti+1][tj]==0){
                    if(mat[ti+1][tj]==1)  dis[ti+1][tj]=level;
                    q.push({ti+1,tj});
                    vis[ti+1][tj]=1;
                }
                if(tj-1>=0 && vis[ti][tj-1]==0){
                    if(mat[ti][tj-1]==1)  dis[ti][tj-1]=level;
                    q.push({ti,tj-1});
                    vis[ti][tj-1]=1;
                }
                if(tj+1<mat[0].size() && vis[ti][tj+1]==0){
                    if(mat[ti][tj+1]==1)  dis[ti][tj+1]=level;
                    q.push({ti,tj+1});
                    vis[ti][tj+1]=1;
                }
            }
        }
        return dis;
    }
};