class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector <int> ids[100], timeOut[100];
        vector <int> message(numberOfUsers);

        for (auto &v : events){
            if (v[0] == "MESSAGE"){
                int time = stoi(v[1]);
                if (v[2] == "HERE"){
                    for (int i = 0; i < numberOfUsers; i++) ids[i].push_back(time);
                }
                else if (v[2] == "ALL"){
                    for (int i = 0; i < numberOfUsers; i++) message[i]++;
                }
                else{
                    int id = 0;
                    for (auto &c : v[2]){
                        if (c >= '0' && c <= '9') id = id * 10 + (c - '0');
                        else if (c == ' '){
                            // ids[id].push_back(time);
                            message[id]++;
                            id = 0;
                        }
                    }
                    // ids[id].push_back(time);
                    message[id]++;
                }
            }
            else{
                int time = stoi(v[1]);
                int id = stoi(v[2]);
                timeOut[id].push_back(time);
            }
        }

        for (auto &v : ids) sort(v.begin(), v.end());
        for (auto &v : timeOut) sort(v.begin(), v.end());

        for (int i = 0; i < numberOfUsers; i++){
            int j = 0, curr = -60;
            for (auto &t : ids[i]){
                while (j < timeOut[i].size() && t >= curr + 60){
                    curr = timeOut[i][j++];
                }
                if (t < curr || t >= curr + 60) message[i]++;
            }
        }

        return message;
    }
};