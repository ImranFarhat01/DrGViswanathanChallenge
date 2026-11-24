class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int temp = i;
            bool flag = true;
            while (temp > 0) {
                int dig = temp % 10;
                if (dig == 0 || i % dig != 0) {
                    flag = false;
                    break;
                }
                temp /= 10;
            }
            if (flag) ans.push_back(i);
        }
        return ans;
    }
};