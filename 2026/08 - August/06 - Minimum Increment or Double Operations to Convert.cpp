class Solution {
  public:
    int countMinOperations(vector<int>& a) {
        int decrement_count = 0;
        int max_divide_count = 0;
        for (int x : a) {
            int divide_count = 0;
            while (x > 0) {
                if (x % 2) {
                    decrement_count++;
                    x--;
                } else {
                    divide_count++;
                    x /= 2;
                }
            }
            max_divide_count = max(max_divide_count, divide_count);
        }
        return decrement_count + max_divide_count;
    }
};
