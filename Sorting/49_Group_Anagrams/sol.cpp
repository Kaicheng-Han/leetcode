class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        } // 储存键值对，key是sort后相同的字母组合，value是不同的变化
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        } // 把每个key所对应的value加入进去
        return ans;
    }
};