class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        for (int i = 0; i < paragraph.length(); i++) {
            if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
                paragraph[i] = paragraph[i] - 'A' + 'a';
            }
        }
        string temp = "";
        for (int i = 0; i < paragraph.length(); i++) {
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
                temp += paragraph[i];
            }
            else {
                if (!temp.empty()) {
                    mp[temp]++;
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            mp[temp]++;
        }
        for (int i = 0; i < banned.size(); i++) {
            if (mp.find(banned[i]) != mp.end()) {
                mp.erase(banned[i]);
            }
        }
        int maxm = 0;
        string ans = "";
        for (auto &it : mp) {
            if (it.second > maxm) {
                maxm = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};