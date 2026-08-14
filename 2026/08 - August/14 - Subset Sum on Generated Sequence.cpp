class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        if (x == 0) {
            return true;
        }
        if (s > x) {
            return false;
        }
        vector<long long> v;
        v.push_back(s);
        long long current_sum = s;
        for (int num : arr) {
            long long new_num = current_sum + num;
            if (new_num > x) {
                break;
            }
            v.push_back(new_num);
            current_sum += new_num;
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] <= x) {
                x -= v[i];
            }
        }
        return x == 0;
    }
};
