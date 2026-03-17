class NumArray {
public:

    vector<int> segTree;
    int n;

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            segTree[idx] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2*idx+1, l, mid, nums);
        build(2*idx+2, mid+1, r, nums);

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;

        if (ql <= l && r <= qr) return segTree[idx];

        int mid = (l + r) / 2;

        return query(2*idx+1, l, mid, ql, qr) +
               query(2*idx+2, mid+1, r, ql, qr);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        build(0, 0, n-1, nums);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

                                                                                                                                                                                               