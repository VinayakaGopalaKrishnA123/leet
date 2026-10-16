class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
       
       
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
         vector<int> col(n,-1);
         col[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int t=q.front(),c=col[t];
            for(auto i:adj[t]){
                if(col[i]==-1){ col[i]=c==1?0:1; q.push(i);}
                else if(col[i]==c) return false;
            }
            q.pop();
        }
        }
        return true;
    }
};