class Solution {
private:
    int f(vector<int>& a, int target) {
        if (target < 0) {
            return 0;
        }
        int n = a.size();
        int l = 0;
        long long cnt = 0;
        long long sum = 0;
        for (int r = 0; r < n; r++) {
            sum += a[r];
            while (sum > target) {
                sum -= a[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return (int)cnt;
    }
public:
    int countSubarray(vector<int>& a, int l, int r) {
        return f(a, r) - f(a, l - 1);
    }
};
