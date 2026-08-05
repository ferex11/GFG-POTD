class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        int m = (int)a.size();
        vector<long long> diff(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int l = a[i];
            int r = b[i];
            diff[l] += k[i];
            if (r + 1 < n) {
                diff[r + 1] -= k[i];
            }
        }
        int cur = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            mx = max(mx, cur);
        }
        return mx;
    }
};
