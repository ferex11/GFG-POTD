class Solution {
private:
    int n;
    vector<int> zAlgo(string& s) {
        vector<int> z(n, 0);
        int l = 0;
        int r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
public:
	string compress(string &s) {
		n = s.size();
		vector<int> z = zAlgo(s);
		string ans = "";
		int i = n - 1;
		while (i >= 0) {
		    int len = i + 1;
		    if (len % 2 == 0) {
		        int half = len / 2;
		        if (z[half] >= half) {
		            ans.push_back('*');
		            i = half - 1;
		            continue;
		        }
		    }
		    ans.push_back(s[i]);
		    i--;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
