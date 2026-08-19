class Solution {
private:
    int n;
    int f(vector<int>& a, int target) {
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                long long sum = 1LL * a[i] + a[j] + a[k];
                if (sum <= target) {
                    cnt += k - j;
                    j++;
                } else {
                    k--;
                }
            }
        }
        return cnt;
    }
public:
    int countTriplets(vector<int> &a, int l, int r) {
        n = a.size();
        sort(a.begin(), a.end());
        return f(a, r) - f(a, l - 1);
    }
};
