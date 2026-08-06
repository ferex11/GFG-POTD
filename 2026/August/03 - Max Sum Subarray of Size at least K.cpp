class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        int ans = INT_MIN;
        int min_prefix = 0;
        for (int i = k; i <= n; i++) {
            min_prefix = min(min_prefix, prefix[i - k]);
            ans = max(ans, prefix[i] - min_prefix);
        }
        return ans;
    }
};
