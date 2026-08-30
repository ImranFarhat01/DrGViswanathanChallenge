class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        ans.resize(s.size() + spaces.size());
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                ans[i + j] = ' ';
                j++;
            }
            ans[i + j] = s[i];
        }
        return ans;
        
    }
};