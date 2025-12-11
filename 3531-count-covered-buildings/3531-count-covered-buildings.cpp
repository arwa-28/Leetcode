class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector <pair <int, int>> x(n + 1, {1e5, 0}), y(n + 1, {1e5, 0});
        for (auto &v : buildings){
            x[v[0]].first = min(x[v[0]].first, v[1]);
            x[v[0]].second = max(x[v[0]].second, v[1]);

            y[v[1]].first = min(y[v[1]].first, v[0]);
            y[v[1]].second = max(y[v[1]].second, v[0]);
        }

        int ans = 0;
        for (auto &v : buildings){
            if (x[v[0]].first < v[1] && x[v[0]].second > v[1] && y[v[1]].first < v[0] && y[v[1]].second > v[0]) ans++;
        }

        return ans;
    }
};