class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        int t=w;
        vector<pair<int,int>> v;
        for(int i=0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            while(k>0 && !pq.empty() && v[i].first>t){
                t+=pq.top();
                pq.pop();
                k--;
            }
            if(v[i].first<=t){
                pq.push(v[i].second);
            }
        }
        while(k>0 && !pq.empty()){
            t+=pq.top();
            pq.pop();
            k--;
        }
        return t;
    }
};