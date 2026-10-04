class Solution {
public:
    int t[101][101];
    bool vps(string &s, int i, int open) {
        if (open < 0) return false;
        if (i == s.length()) return open == 0;
        if (t[i][open] != -1) return t[i][open];
        if (s[i] == '(')
            return t[i][open] = vps(s, i + 1, open + 1);
        if (s[i] == ')')
            return t[i][open] = vps(s, i + 1, open - 1);
        return t[i][open] = vps(s, i + 1, open + 1) ||
                            vps(s, i + 1, open - 1) ||
                            vps(s, i + 1, open);
    }
    bool checkValidString(string s) {
        memset(t, -1, sizeof(t));
        int open = 0, i = 0;
        int starcnt = count(s.begin(), s.end(), '*');
        if (starcnt == s.length()) return true;
        return vps(s, i, open);
    }
};