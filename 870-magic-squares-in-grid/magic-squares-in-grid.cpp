class Solution {
public:
    bool isMagic(vector<vector<int>>& g,int i,int j){
        if(g[i][j]!=5) return false;
        bool used[10]={false};
        for(int r=i-1;r<=i+1;r++){
            for(int c=j-1;c<=j+1;c++){
                int v=g[r][c];
                if(v<1||v>9||used[v]) return false;
                used[v]=true;
            }
        }
        if(g[i-1][j-1]+g[i+1][j+1]!=10) return false;
        if(g[i-1][j+1]+g[i+1][j-1]!=10) return false;
        if(g[i-1][j]+g[i+1][j]!=10) return false;
        if(g[i][j-1]+g[i][j+1]!=10) return false;
        if(g[i-1][j-1]+g[i-1][j]+g[i-1][j+1]!=15) return false;
        if(g[i+1][j-1]+g[i+1][j]+g[i+1][j+1]!=15) return false;
        if(g[i-1][j-1]+g[i][j-1]+g[i+1][j-1]!=15) return false;
        if(g[i-1][j+1]+g[i][j+1]+g[i+1][j+1]!=15) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i!=0 && i!=grid.size()-1 && j!=grid[i].size()-1 && j!=0 && isMagic(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};