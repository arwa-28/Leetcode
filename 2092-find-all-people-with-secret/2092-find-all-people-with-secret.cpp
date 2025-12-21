class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int N = 1e5 + 1;
        vector <pair <int, int>> g[N];
        for (auto &v : meetings){
            g[v[0]].push_back({v[1], v[2]});
            g[v[1]].push_back({v[0], v[2]});
        }

        vector <bool> vis(n);
        vector <int> ans;

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()){
            auto [currt, v] = pq.top();
            pq.pop();
            if (vis[v]) continue;
            vis[v] = 1;
            ans.push_back(v);
            for (auto &[u, t] : g[v]){
                if (t >= currt && !vis[u]){
                    pq.push({t, u});
                    // ans.push_back(u);
                }
            }
        }
        return ans;
    }
};