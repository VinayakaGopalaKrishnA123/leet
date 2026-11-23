class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i*i<=n;i++){
            squares.push_back(i*i);
        }
        queue<int>q;
        vector<int> vis(n+1,0);
        int ans=0;
        q.push(n);
        vis[n]=1;
        while(!q.empty()){
            int qs=q.size();
            ans++;
            for(int i=0;i<qs;i++){
                int curr=q.front();
                q.pop();
                for(int sq:squares){
                    if(curr<sq) break;
                    int next=curr-sq;
                    if(next==0) return ans;
                    if(!vis[next]){
                        vis[next]=1;
                        q.push(next);
                    }
                }

            }
        }
        return ans;
    }
};