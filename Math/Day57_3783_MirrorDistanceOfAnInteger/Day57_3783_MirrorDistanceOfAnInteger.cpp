class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int temp = n;
        while (temp > 0) {
            int t = temp % 10;
            rev = rev * 10 + t;
            temp /= 10;
        }
        return abs(n - rev);
    }
};