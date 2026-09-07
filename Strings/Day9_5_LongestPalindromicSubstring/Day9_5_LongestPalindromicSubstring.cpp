class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(string &s, int i, int j) {
        if (t[i][j] != -1)
            return t[i][j];
        if (i >= j)
            return true;
        if (s[i] == s[j])
            return t[i][j] = isPalindrome(s, i + 1, j - 1);
        else {
            return t[i][j] = false;
        }
    }
    string longestPalindrome(string s) {
        int maxlen = 0;
        memset(t, -1, sizeof(t));
        int startPoint = -1;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) == true && j - i + 1 > maxlen) {
                    maxlen = max(j - i + 1, maxlen);
                    startPoint = i;
                }
            }
        }
        return s.substr(startPoint, maxlen);
    }
};