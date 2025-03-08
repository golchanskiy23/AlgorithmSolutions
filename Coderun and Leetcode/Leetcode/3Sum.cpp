class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();++i){
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[l]+nums[r]+nums[i];
                if(sum > 0){
                    --r;
                }
                else if(sum < 0) ++l;
                else{
                    ans.push_back({nums[i],nums[l],nums[r]}); 
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};