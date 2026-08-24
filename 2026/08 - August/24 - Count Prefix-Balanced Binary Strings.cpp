class Solution {
public:
    int prefixStrings(int n) {
        const long long mod = 1e9 + 7;
        vector<int> inv(n + 2);
        inv[1] = 1;
        for (int i = 2; i <= n + 1; i++) {
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        }
        long long ans = 1;
        for (long long i = 1; i <= n; i++) {
            ans = ans * (4 * i - 2) % mod;
            ans = ans * inv[i + 1] % mod;
        }
        return ans;
    }
};
