class Solution {
public:
    int findSmallest(vector<int> &a) {
        sort(a.begin(), a.end());
        int x = 1;
        for (int val : a) {
            if (val > x) {
                return x;
            }
            x += val;
        }
        return x;
    }
};
