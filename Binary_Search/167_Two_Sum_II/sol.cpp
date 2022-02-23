// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0; 
        int high = numbers.size() - 1;
        while(low < high) {
            int sum = numbers[low] + numbers[high];
            if(sum == target) {
                return {low + 1, high + 1};
            }
            else if(sum < target) {
                ++low;
            }
            else {
                --high;
            }
        }
        return {-1, -1};
    }
};

// Binary Search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};