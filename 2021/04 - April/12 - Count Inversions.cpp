// Using Merge sort
class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int cnt = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); 
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};

// Using Segment Tree
class SegmentTree {
private:
    int n;
    vector<int> tree;
    void update(int ind, int low, int high, int pos) {
        if (low == high) {
            tree[ind]++;
            return;
        }
        int mid = low + (high - low) / 2;
        if (pos <= mid) {
            update(2 * ind + 1, low, mid, pos);
        } else {
            update(2 * ind + 2, mid + 1, high, pos);
        }
        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
    }
    int query(int ind, int low, int high, int l, int r) {
        if (l > high || r < low) {
            return 0;
        }
        if (l <= low && high <= r) {
            return tree[ind];
        }
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n + 1, 0);
    }
    void setValue(int pos) {
        update(0, 1, n, pos);
    }
    int getMinCount(int l, int r) {
        if (l > r) {
            return 0;
        }
        return query(0, 1, n, l, r);
    }
};
class Solution {
public:
    int inversionCount(vector<int> &arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int n = sorted.size();
        SegmentTree st(n);
        long long cnt = 0;
        for (int x : arr) {
            int rank = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
            cnt += st.getMinCount(rank + 1, n);
            st.setValue(rank);
        }
        return cnt;
    }
};
