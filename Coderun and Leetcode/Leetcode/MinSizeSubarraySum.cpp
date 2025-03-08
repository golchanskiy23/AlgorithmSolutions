class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), minWindow = 1000000001, curr_sum = nums[0];
        while(r < n){
            if(curr_sum < target){
                ++r;
                if(r == n) break;
                curr_sum += nums[r];
            }
            else{
                minWindow = std::min(minWindow, r-l+1);
                curr_sum -= nums[l];
                ++l;
            }
        }
        if(minWindow == 1000000001) return 0;
        return minWindow;
    }
};