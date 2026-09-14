class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x1_ = rec2[0], y1_ = rec2[1], x2_ = rec2[2], y2_ = rec2[3];
        if (x1_ >= x2 || x2_ <= x1) {
            return false;
        }
        if (y1_ >= y2 || y2_ <= y1) {
            return false;
        }
        return true;
    }
};