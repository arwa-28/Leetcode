class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while (true){
            string temp = s;
            s += '1';

            while (!temp.empty()){
                char c = temp.back();
                temp.pop_back();
                s += (c == '0') ? '1' : '0';
            }

            if (s.size() >= k) return s[k - 1];
        }
    }
};