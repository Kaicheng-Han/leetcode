class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return {};
        }
        else {
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> merged;
            for(int i = 0; i < intervals.size(); ++i) {
                int l = intervals[i][0], r = intervals[i][1];
                if(merged.empty() || merged.back()[1] < l) {
                    merged.push_back(intervals[i]);
                }
                else {
                    merged.back()[1] = max(merged.back()[1], r);
                }
            }
            return merged;
        }
    }
};