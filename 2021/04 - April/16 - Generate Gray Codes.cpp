class Solution {
  public:
    vector<string> graycode(int n) {
        if (n == 1)
            return {"0", "1"};
        vector<string> prevGray = graycode(n - 1);
        vector<string> res;
        int sz = prevGray.size();
        for (int i = 0; i < sz; i++)
            res.push_back("0" + prevGray[i]);
        for (int i = sz - 1; i >= 0; i--)
            res.push_back("1" + prevGray[i]);
        return res;
    }
};
