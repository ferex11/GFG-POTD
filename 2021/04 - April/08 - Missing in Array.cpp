class Solution {
public:
    int missingNum(vector<int>& a) {
        int n = a.size();
        int xr = 0;
        for (int x : a) {
            xr ^= x;
        }
        for (int i = 1; i <= n + 1; i++) {
            xr ^= i;
        }
        return xr;
    }
};
