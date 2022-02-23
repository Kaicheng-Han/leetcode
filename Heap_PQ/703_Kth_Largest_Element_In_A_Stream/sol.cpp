class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& item : nums) {
            add(item);
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k) {
            q.pop();
        }
        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */