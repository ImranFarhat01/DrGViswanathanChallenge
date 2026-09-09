class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(begin(temp), end(temp));
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (const auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};