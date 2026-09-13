class Solution {
public:
    bool check(string s, int l, int r, int k) {
        int zero = 0;
        int one = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '0') {
                zero++;
            }
            if (s[i] == '1') {
                one++;
            }
        }
        if (zero <= k || one <= k) {
            return true;
        }
        return false;
    }
    int countKConstraintSubstrings(string s, int k) {
        int l = 0, r = 0, countSubstr = 0;
        int n = s.length();
        while (r < n) {
            while (!check(s, l, r, k)) {
                l++;
            }
            countSubstr += r - l + 1;
            r++;
        }
        return countSubstr;
    }
};