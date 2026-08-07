class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j <= i) {
                j = i + 1;
            }
            while (j < n && arr[j] - arr[i] < k) {
                j++;
            }
            cnt += (j - i - 1);
        }
        return cnt;
    }
};
