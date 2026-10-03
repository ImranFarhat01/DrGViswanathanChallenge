class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxm = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') open++;
            else if (s[i] == ')') close++;
            if (open == close) maxm = max(maxm, open * 2);
            else if (close > open) {
                open = 0, close = 0;
            }
        }
        open = 0, close = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else if (s[i] == ')') close++;
            if (open == close) maxm = max(maxm, open * 2);
            else if (open > close) {
                open = 0, close = 0;
            }
        }
        return maxm;
    }
};