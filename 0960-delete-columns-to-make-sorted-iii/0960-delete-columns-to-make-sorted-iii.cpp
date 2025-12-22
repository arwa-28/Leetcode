class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector <vector <int>> dp(n, vector <int> (n, 1e9));
        function <int(int, int, bool)> go = [&](int i, int prev, bool flag){
            if (i == n) return 0;

            if (dp[i][prev] != 1e9) return dp[i][prev];

            int &ans = dp[i][prev];
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