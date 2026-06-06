class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<vector<int>> q;
        vector<vector<int>> m(image.size(),vector<int> (image[0].size(),0));
        int stp=image[sr][sc];
        q.push({sr,sc});
        while(!q.empty()){
            vector<int> ar=q.front();
            q.pop();
            int i=ar[0],j=ar[1];
            if(m[i][j]==0  && image[i][j]==stp){
                image[i][j]=color;
                if(i-1>=0 && m[i-1][j]==0) q.push({i-1,j});
                if(j-1>=0) q.push({i,j-1});
                if(i<image.size()-1) q.push({i+1,j});
                if(j<image[0].size()-1) q.push({i,j+1});
            }
            m[i][j]=1;
        }
        return image;
    }
};