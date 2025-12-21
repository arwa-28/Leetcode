class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, n = strs[0].size();
        vector <bool> skip(strs.size());

        for (int i = 0; i < n; i++){
            bool ok = 1, equal = 0;
            vector <int> temp;
            for (int j = 1; j < strs.size(); j++){
                if (skip[j]) continue;
                if (strs[j][i] < strs[j - 1][i]){
                    ok = 0;
                    ans++;
                    break;
                }
                else if (strs[j][i] == strs[j - 1][i]) equal = 1;
                else temp.push_back(j);
            }
            if (ok && !equal) break;
            
            if (ok) for (auto &x : temp) skip[x] = 1;
        }

        return ans;
    }
};