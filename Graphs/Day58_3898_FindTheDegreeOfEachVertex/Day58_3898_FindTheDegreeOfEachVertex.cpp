class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int r = 0; r < matrix.size(); r++) {
            int temp = 0;
            for (int c = 0; c < matrix[0].size(); c++) {
                temp += matrix[r][c];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};