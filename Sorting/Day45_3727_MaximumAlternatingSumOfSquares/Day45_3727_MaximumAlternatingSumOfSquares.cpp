class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int half = (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < half; i++) {
            ans += 1LL * nums[i] * nums[i];
        }
        for (int i = half; i < n; i++) {
            ans -= 1LL * nums[i] * nums[i];
        }
        return ans;
    }
};