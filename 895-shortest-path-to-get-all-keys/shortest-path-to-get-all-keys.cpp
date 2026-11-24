class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int nk=0;
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>='a' && grid[i][j]<='z') nk++;    
            }
        }
        vector<vector<vector<int>>> vis(rows,vector<vector<int>>(cols,vector<int>(1<<nk,0)));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='@') {q.push({i,j,0}); vis[i][j][0]=1;}
            }
        }
        int level=0;
        while(!q.empty()){
            int qs=q.size();
            for(int i=0;i<qs;i++){
                auto top=q.front();
                int ti=top[0],tj=top[1],mask=top[2];
                q.pop();
                if(mask==(1<<nk)-1) return level;
                int dr[]={-1,1,0,0};
                int dc[]={0,0,-1,1};
                for(int k=0;k<4;k++){
                    int nr=ti+dr[k];
                    int nc=tj+dc[k];
                    if(nr<0||nr>=rows||nc<0||nc>=cols) continue;
                    char ch=grid[nr][nc];
                    if(ch=='#') continue;
                    int newMask=mask;
                    if(ch>='a' && ch<='f') newMask|=(1<<(ch-'a'));
                    if(ch>='A' && ch<='F')  { 
                        if(!(mask&(1<<(ch-'A'))))  continue;
                    }
                    if(!vis[nr][nc][newMask]){
                        vis[nr][nc][newMask]=1;
                        q.push({nr,nc,newMask});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};