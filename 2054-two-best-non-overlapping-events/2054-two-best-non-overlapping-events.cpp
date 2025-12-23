class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int ans = 0, mx = 0;
        for (auto &v : events){
            while(!pq.empty() && pq.top().first < v[0]){
                mx = max(mx, pq.top().second);
                pq.pop();
            }
            ans = max(ans, v[2] + mx);
            pq.push({v[1], v[2]});
        }   

        return ans;
    }
};