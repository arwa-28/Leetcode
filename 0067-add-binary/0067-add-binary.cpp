class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int aa = 0, bb = 0, carry = 0;
        while (!a.empty() || !b.empty()){
            if (!a.empty()){
                aa = a.back() - '0';
                a.pop_back();
            }
            else aa = 0;

            if (!b.empty()){
                bb = b.back() - '0';
                b.pop_back();
            }
            else bb = 0;

            sum += (aa + bb + carry == 1) ? '1' : '0';

            if (aa + bb + carry >= 2) carry = 1;
            else carry = 0;
        }

        if (carry) sum += '1';
        reverse(sum.begin(), sum.end());

        return sum;
    }
};