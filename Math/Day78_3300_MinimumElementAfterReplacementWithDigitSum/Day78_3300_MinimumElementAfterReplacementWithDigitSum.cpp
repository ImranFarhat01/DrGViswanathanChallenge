class Solution {
public:
    int minElement(vector<int>& nums) {
        int minm = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            minm = min(minm, sum);
        }
        return minm;
    }
};