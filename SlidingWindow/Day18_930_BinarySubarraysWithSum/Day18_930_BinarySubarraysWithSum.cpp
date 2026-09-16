class Solution {
public:
    int numSubarr(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        int n = nums.size();
        int sum = 0, ans = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) {
            return numSubarr(nums, 0);
        }
        return numSubarr(nums, goal) - numSubarr(nums, goal - 1);
    }
};