class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            int temp = n % 10;
            freq[temp]++;
            n /= 10;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += i * freq[i];
        }
        return ans;
    }
};