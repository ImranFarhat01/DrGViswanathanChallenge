class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int open = 0;
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            }
            if (s[i] == ')') {
                open--;
                if (s[i-1] == '(') {
                    score += pow(2, open);
                }
            }
        }
        return score;
    }
};