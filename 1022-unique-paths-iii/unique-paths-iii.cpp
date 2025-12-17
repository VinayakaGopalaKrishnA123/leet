class Solution {
public:
    int c=0;
    int countofminusone=0;
    void f(int si,int sj,vector<vector<int>> v,vector<vector<int>> g,int vc){
        if(g[si][sj]==2){
            if(vc+1==g.size()*g[0].size()-countofminusone) c++;
            return;
        }
        v[si][sj]=1;
        if(si+1<g.size()&&g[si+1][sj]!=-1&&v[si+1][sj]==0)  f(si+1,sj,v,g,vc+1);
        if(si-1>=0&&g[si-1][sj]!=-1&&v[si-1][sj]==0) f(si-1,sj,v,g,vc+1);
        if(sj+1<g[0].size()&&g[si][sj+1]!=-1&&v[si][sj+1]==0)   f(si,sj+1,v,g,vc+1);
        if(sj-1>=0&&g[si][sj-1]!=-1&&v[si][sj-1]==0) f(si,sj-1,v,g,vc+1);
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si,sj;
        vector<vector<int>> v(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
                if(grid[i][j]==-1){
                    countofminusone++;
                }
            }
        }
        // v[si][sj]=1;
        f(si,sj,v,grid,0);
        return c;
    }
};