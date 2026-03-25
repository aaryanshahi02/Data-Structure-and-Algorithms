class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        return mergeSortAndCount(pre, 0, n, lower, upper);
    }

private:
    int mergeSortAndCount(vector<long long>& pre, int left, int right, int lower, int upper) {

        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(pre, left, mid, lower, upper) + mergeSortAndCount(pre, mid + 1, right, lower, upper);

        int j = mid + 1;
        int k = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && pre[j] - pre[i] < lower)
                j++;
            while (k <= right && pre[k] - pre[i] <= upper)
                k++;
            count += (k - j);
        }

        vector<long long> temp(right - left + 1);
        int p1 = left, p2 = mid + 1, p = 0;

        while (p1 <= mid && p2 <= right) {
            if (pre[p1] <= pre[p2])
                temp[p++] = pre[p1++];
            else
                temp[p++] = pre[p2++];
        }
        while (p1 <= mid)
            temp[p++] = pre[p1++];
        while (p2 <= right)
            temp[p++] = pre[p2++];

        for (int i = 0; i < temp.size(); i++) {
            pre[left + i] = temp[i];
        }

        return count;
    }
};