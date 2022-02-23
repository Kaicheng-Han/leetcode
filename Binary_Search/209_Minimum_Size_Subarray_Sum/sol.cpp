// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //滑动窗口法
        int ans = INT_MAX;
        int n = nums.size();
        if(n == 0) return 0;
        int left = 0, right = 0, sum = 0;
        while(right < n) {
            sum += nums[right];
            while(sum >= target) { // 加起来超过7的话left右滑，不然right右滑
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// binary search
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};