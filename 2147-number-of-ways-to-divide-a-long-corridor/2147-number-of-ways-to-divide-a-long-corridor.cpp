class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9 + 7;
        long long Scnt = 0, Pcnt = 0, ans = 0;

        for (int i = 0; i < corridor.size(); i++){
            if (corridor[i] == 'S'){
                if (Pcnt && Scnt && Scnt % 2 == 0){
                    ans = max(ans, 1ll) * (Pcnt + 1) % mod;
                    ans %= mod;
                }
                Pcnt = 0;
                Scnt++;
            }
            else Pcnt++;
        }    

        if (!ans) ans++;

        return (Scnt % 2 || !Scnt) ? 0 : ans;
    }
};