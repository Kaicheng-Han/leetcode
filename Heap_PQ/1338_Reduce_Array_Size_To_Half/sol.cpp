class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;

        for(auto item : arr) {
            map[item]++;
        }

        priority_queue<int> pq;
        for(auto it : map) {
            pq.push(it.second);
        }

        int del = 0;
        int ans = 0;
        while(!pq.empty()) {
            del += pq.top();
            pq.pop();
            ++ans;
            if(del >= n / 2) {
                break;
            }
        }
        return ans;
    }
};