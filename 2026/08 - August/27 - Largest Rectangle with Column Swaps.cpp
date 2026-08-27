class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            vector<int> sorted_height = height;
            sort(sorted_height.rbegin(), sorted_height.rend());
            for (int j = 0; j < m; j++) {
                int h = sorted_height[j];
                int w = j + 1;
                ans = max(ans, h * w);
            }
        }
        return ans;
    }
};
