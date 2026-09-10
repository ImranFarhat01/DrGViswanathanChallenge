class Solution {
public:
    int maxm(unordered_map<int, int> &mp) {
        int maxm = INT_MIN;
        int key;
        for (auto &it : mp) {
            if (it.second > maxm) {
                maxm = it.second;
                key = it.first;
            }
        }
        mp.erase(key);
        return key;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            int temp = maxm(mp);
            ans.push_back(temp);
        }
        return ans;
    }
};