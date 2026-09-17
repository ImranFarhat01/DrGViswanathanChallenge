class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1;
        for (int i = 0; i <= n - m; i++) {
            if (haystack[i] != needle[0])
                continue;
            int j = 1;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};