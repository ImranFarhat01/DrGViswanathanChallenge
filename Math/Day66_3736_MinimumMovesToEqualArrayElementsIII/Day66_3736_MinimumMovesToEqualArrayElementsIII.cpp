class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxm = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return n * maxm - sum;
    }
};