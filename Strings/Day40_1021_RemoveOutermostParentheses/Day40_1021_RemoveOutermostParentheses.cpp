class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int countLeft = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' && countLeft++ > 0) {
                ans.push_back(s[i]);
            }
            if (s[i] == ')' && countLeft-- > 1) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};