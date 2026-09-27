class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                int left = st.top();
                st.pop();
                reverse(s.begin() + left + 1, s.begin() + i);
            }
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            }
        }
        return ans;
    }
};