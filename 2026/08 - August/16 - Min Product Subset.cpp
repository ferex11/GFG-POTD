class Solution {
public:
    int minProd(vector<int>& a) {
        int p = 1;
        int cnt_negative = 0;
        int max_negative = INT_MIN;
        int min_positive = INT_MAX;
        bool has_zero = false;
        for (int x : a) {
            if (x == 0) {
                has_zero = true;
                continue;
            }
            p *= x;
            if (x < 0) {
                cnt_negative++;
                max_negative = max(max_negative, x);
            } else {
                min_positive = min(min_positive, x);
            }
        }
        if (cnt_negative == 0) {
            if (has_zero) {
                return 0;
            }
            return min_positive;
        } else {
            if (cnt_negative % 2 == 1) {
                return p;
            } else {
                return p / max_negative;
            }
        }
        return 0;
    }
};
