class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxlen = 0;
        int freq[26] = {0};
        int maxFreq = 0;
        while (r < n) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            if (r - l + 1 - maxFreq > k) {
                freq[s[l] - 'A']--;
                maxFreq = 0;
                l++;
            }
            if (r - l + 1 - maxFreq <= k) {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};