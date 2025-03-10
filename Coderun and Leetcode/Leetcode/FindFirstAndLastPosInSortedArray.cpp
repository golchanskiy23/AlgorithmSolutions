class Solution {
public:
    int findMin(const vector<int>& v, int l, int r, int target) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if (v[mid] == target) {
            int leftSearch = findMin(v, l, mid - 1, target);
            return (leftSearch != -1) ? leftSearch : mid;
        }
        if (v[mid] < target) return findMin(v, mid + 1, r, target);
        return findMin(v, l, mid - 1, target);
    }

    int findMax(const vector<int>& v, int l, int r, int target) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if (v[mid] == target) {
            int rightSearch = findMax(v, mid + 1, r, target);
            return (rightSearch != -1) ? rightSearch : mid;
        }
        if (v[mid] > target) return findMax(v, l, mid - 1, target);
        return findMax(v, mid + 1, r, target);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v = {-1, -1};
        if (nums.empty()) return v;
        v[0] = findMin(nums, 0, nums.size() - 1, target);
        v[1] = findMax(nums, 0, nums.size() - 1, target);
        return v;
    }
};
