class Solution {
public:
    int n;
    unordered_set<string> ans;
    int maxlen = 0;
    void generate(int i, string &curr, int open, string &s) {
        if (open < 0) return;
        if (i == n) {
            if (open == 0) {
                if (curr.length() > maxlen) {
                    maxlen = curr.length(), ans.clear();
                }
                if (curr.length() == maxlen) ans.insert(curr);
            }
            return;
        }
        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            generate(i + 1, curr, open, s);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        generate(i + 1, curr, open + (s[i] == '(' ? 1 : -1), s);
        curr.pop_back();
        generate(i + 1, curr, open, s);
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        ans.clear();
        maxlen = 0;
        string curr = "";
        generate(0, curr, 0, s);
        return vector<string>(ans.begin(), ans.end());
    }
};