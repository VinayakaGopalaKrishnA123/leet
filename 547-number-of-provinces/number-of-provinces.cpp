class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1) v[i].push_back(j);
            }
        }
        vector<int> vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(auto x : v[temp]) {
                        if(!vis[x]) {
                            vis[x] = 1;
                            q.push(x);
                        }
                    }
                }
            }
        }
        return ans;
    }
};