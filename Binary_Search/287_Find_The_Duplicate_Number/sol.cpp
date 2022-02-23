class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 1, right = size - 1;
        while(left < right) {
            // 中间数
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int num : nums) {
                if(num <= mid) {
                    ++count; // 记录小于等于中间数的数量
                }
            }
            // 如果该数量大于中间数，说明区间在左边，不然在右边
            if(count > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};