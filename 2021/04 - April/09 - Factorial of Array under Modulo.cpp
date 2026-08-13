class Solution {
public:
    vector<int> factorial(vector<int> &a) {
        const int mod = (int) 1e9 + 7;
        int mx = *max_element(a.begin(), a.end());
        vector<long long> fact(mx + 1);
        fact[0] = 1;
        for (int i = 1; i <= mx; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        vector<int> ans;
        for (int x : a) {
            ans.push_back(fact[x]);
        }
        return ans;
    }
};
