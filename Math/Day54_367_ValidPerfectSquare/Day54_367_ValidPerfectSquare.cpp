class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; 1LL * i * i <= num; i++) {
            if (1LL * i * i == num)
                return true;
        }
        return false;
    }
};