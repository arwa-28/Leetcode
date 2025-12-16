class Solution {
public:
    int countOdds(int low, int high) {
        return high - low + min(low, 1) - (high / 2 - (low - 1) / 2);
    }
};