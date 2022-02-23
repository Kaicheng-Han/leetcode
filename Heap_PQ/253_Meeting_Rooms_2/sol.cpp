class Solution {
    
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(), intervals.end(), [](vector<int> &x1, vector<int> &x2) {
            return x1[0] < x2[0];
        });
        priority_queue<int, vector<int>, greater<int>()> heap;
        for(auto& val : intervals) {
            if(heap.empty() || val[0] < heap.top()) {
                heap.push(val[1]);
            }
            else {
                heap.pop();
                heap.push(val[1]);
            }
        }
        return heap.size();
    }
};