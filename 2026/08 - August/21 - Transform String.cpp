class Solution {
public:
    int transform(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m) {
            return -1;
        }
        vector<int> freq(128, 0);
        for (int i = 0; i < n; i++) {
            freq[s1[i]]++;
            freq[s2[i]]--;
        }
        for (int i = 0; i < 128; i++) {
            if (freq[i]) {
                return -1;
            }
        }
        int j = n - 1;
        int cnt = 0;
        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && s1[j] != s2[i]) {
                j--;
            }
            if (j >= 0) {
                cnt++;
                j--;
            } else {
                break;
            }
        }
        return n - cnt;
    }
};
