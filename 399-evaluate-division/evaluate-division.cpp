class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0 / w});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string src = q[0];
            string dst = q[1];

            if (!adj.count(src) || !adj.count(dst)) {
                ans.push_back(-1.0);
                continue;
            }

            if (src == dst) {
                ans.push_back(1.0);
                continue;
            }

            queue<pair<string, double>> qu;
            unordered_set<string> vis;

            qu.push({src, 1.0});
            vis.insert(src);

            double res = -1.0;

            while (!qu.empty()) {
                auto [node, val] = qu.front();
                qu.pop();

                if (node == dst) {
                    res = val;
                    break;
                }

                for (auto &[nbr, wt] : adj[node]) {
                    if (!vis.count(nbr)) {
                        vis.insert(nbr);
                        qu.push({nbr, val * wt});
                    }
                }
            }

            ans.push_back(res);
        }
        return ans;
    }
};