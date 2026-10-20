class Solution {
public:
    int sumDig(int num) {
        int ans = 0;
        while (num > 0) {
            int temp = num % 10;
            ans += temp;
            num /= 10;
        }
        return ans;
    }
    int addDigits(int num) {
        while (num / 10 > 0) {
            num = sumDig(num);
        }
        return num;
    }
};