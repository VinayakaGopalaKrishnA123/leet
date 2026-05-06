class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>> v(grid.size(),vector<int> (grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int tans=0;
                if(grid[i][j]==1 && v[i][j]==0){
                    queue<vector<int>> q;
                    q.push({i,j});
                    v[i][j]=1;
                    while(!q.empty()){
                        // cout<<1<<'\n';
                        vector<int> vv=q.front();
                        tans++;
                        q.pop();
                        int ti=vv[0],tj=vv[1];
                       
                        if(ti>0 && grid[ti-1][tj]==1 && v[ti-1][tj]==0) {q.push({ti-1,tj}); v[ti-1][tj]=1;}
                        if(tj>0 && grid[ti][tj-1]==1 && v[ti][tj-1]==0) {q.push({ti,tj-1}); v[ti][tj-1]=1;}
                        if(ti<grid.size()-1 && grid[ti+1][tj]==1 && v[ti+1][tj]==0) {q.push({ti+1,tj}); v[ti+1][tj]=1;}
                        if(tj<grid[ti].size()-1 && grid[ti][tj+1]==1 && v[ti][tj+1]==0) {q.push({ti,tj+1});v[ti][tj+1]=1;}
                    }
                }
                ans=max(ans,tans);
            }
        }
        return ans;
    }
};