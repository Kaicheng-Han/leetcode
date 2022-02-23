// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> s;
//         for(int i : nums) {
//             if(s.find(i) != s.end()) {
//                 return true;
//             }
//             s.insert(i);
//         }
//         return false;

//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};