class Solution {
public:
    bool possible(string s, int l, int r) {
        int freq[26] = {0};
        for (int i = l; i <= r; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 1) {
                return false;
            }
        }
        return true;
    }
    int countGoodSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        int l = 0;
        int r = 2;
        while (r < n) {
            if (possible(s, l, r)) {
                cnt++;
            }
            l++;
            r++;
        }
        return cnt;
    }
};