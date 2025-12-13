class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector <pair <string, string>> v;   
        
        for (int i = 0; i < code.size(); i++){
            if (!isActive[i] || code[i].empty()) continue;

            if (businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant") continue;
            bool ok = 1;
            for (auto &c : code[i]){
                if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z') && !('0' <= c && c <= '9') && !(c == '_')){
                    ok = 0;
                    break;
                }
            }
            if (ok) v.push_back({businessLine[i], code[i]});
        }

        sort(v.begin(), v.end());

        vector <string> codes;

        for (auto &[b, s] : v) codes.push_back(s);

        return codes;
    }
};