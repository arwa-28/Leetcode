class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2, 1e9)));
        // vector <vector <int>> dp(n, vector <int> (n, 1e9));
        function <int(int, int, bool)> go = [&](int i, int prev, bool flag){
            if (i == n) return 0;

            if (dp[i][prev][flag] != 1e9) return dp[i][prev][flag];

            int &ans = dp[i][prev][flag];
            if (flag){
                bool ok = 1;
                for (auto &s : strs) ok &= s[prev] <= s[i];
                if (ok) ans = go(i + 1, i, 1);
            }
            else ans = go(i + 1, i, 1);
            ans = min(ans, go(i + 1, prev, flag) + 1);

            return ans;
        };

        return go(0, 0, 0);
    }
};