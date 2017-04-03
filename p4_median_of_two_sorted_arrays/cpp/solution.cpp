class Solution {
public:
    int getkth(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        // let m <= n
        if (m > n)
            return getkth(nums2, nums1, k);
        if (m == 0)
            return nums2[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);

        int i = min(m, k / 2), j = min(n, k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            vector<int> rst_nums2(nums2.begin()+j, nums2.end());
            return getkth(nums1, rst_nums2, k - j);
        } else {
            vector<int> rst_nums1(nums1.begin()+i, nums1.end());
            return getkth(rst_nums1, nums2, k - i);
        }
        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getkth(nums1, nums2, l) + getkth(nums1, nums2, r)) / 2.0;
    }
};
