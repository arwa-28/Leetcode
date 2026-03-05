class Solution {
public:
    int minOperations(string s) {
        char x = '0';
        int cnt1 = 0, cnt2 = 0;
        for (char c : s){
            if (c != x) cnt1++;
            else cnt2++;

            if (x == '0') x = '1';
            else x = '0';
        }

        return min(cnt1, cnt2);
    }
};