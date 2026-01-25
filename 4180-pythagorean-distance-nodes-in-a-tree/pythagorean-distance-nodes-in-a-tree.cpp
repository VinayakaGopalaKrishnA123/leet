class Solution {
public:
    vector<int> bfs(int n,vector<vector<int>> &g,int s){
        vector<int> dis(n,INT_MAX);
       
        dis[s]=0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(auto i:g[t]){
                if(dis[i]>dis[t]+1){
                    dis[i]=dis[t]+1;
                    q.push(i);
                }
            }
        }
        return dis;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> g(n);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> disx=bfs(n,g,x);
        vector<int> disy=bfs(n,g,y);
        vector<int> disz=bfs(n,g,z);
        int ans=0;
        for(int i=0;i<disx.size();i++){
            vector<int> te(3);
            te[0]=disx[i];
            te[1]=disy[i];
            te[2]=disz[i];
            sort(te.begin(),te.end());
            if(pow(te[0],2)+pow(te[1],2)==pow(te[2],2)) ans++;
            // cout<<disx[i]<<" "<<disy[i]<<" "<<disz[i]<<' '<<ans<<"\n";
        }
        return ans;
    }
};