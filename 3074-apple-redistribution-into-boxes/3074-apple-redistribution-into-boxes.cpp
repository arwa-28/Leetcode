class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (auto &x : apple) sum += x;

        sort(capacity.rbegin(), capacity.rend());
        int cnt = 0, res = 0;
        for (auto &x : capacity){
            if (cnt >= sum) break;
            cnt += x;
            res++;
        }

        return res;
    }
};