// Brute force approach
class Solution {
public:
    int countWithout(int n, int d) {
        int cnt = 0;
        auto check = [&](int x) -> bool {
            while (x > 0) {
                int digit = x % 10;
                if (x == d) {
                    return false;
                }
                x /= 10;
            }
            return true;
        };
        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};

// Optimal Approach
