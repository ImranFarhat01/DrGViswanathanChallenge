class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, zeros = 0, ones = 0;
        int n = nums.size();
        while (end < n) {
            if (nums[end] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if (nums[start] == 0)
                    zeros--;
                start++;
            }
            ones = max(ones, end - start + 1);
            end++;
        }
        return ones;
    }
};