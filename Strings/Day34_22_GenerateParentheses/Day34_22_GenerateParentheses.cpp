class Solution {
public:
    vector<string> result;
    void generate(string &curr, int open, int close, int n) {
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            generate(curr, open + 1, close, n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            generate(curr, open, close + 1, n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open = 0, close = 0;
        generate(curr, open, close, n);
        return result;
    }
};