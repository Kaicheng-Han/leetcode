class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; ++i) {
            pq.emplace(points[i][0]*points[i][0]+points[i][1]*points[i][1], i);
        }
        for(int i = k; i < n; ++i) {
            int dis = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(dis < pq.top().first) {
                pq.pop();
                pq.emplace(dis, i);
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.emplace_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};