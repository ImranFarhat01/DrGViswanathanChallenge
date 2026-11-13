class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxm = INT_MIN;
        for (int r = 0; r < accounts.size(); r++) {
            int temp = 0;
            for (int c = 0; c < accounts[0].size(); c++) {
                temp += accounts[r][c];
            }
            maxm = max(maxm, temp);
        }
        return maxm;
    }
};