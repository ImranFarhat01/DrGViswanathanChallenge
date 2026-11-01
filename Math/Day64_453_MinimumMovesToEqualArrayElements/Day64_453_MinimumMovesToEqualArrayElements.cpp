class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return sum - 1LL * n * minVal;
    }
};