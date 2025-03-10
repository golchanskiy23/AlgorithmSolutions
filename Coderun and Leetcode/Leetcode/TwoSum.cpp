class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        std::vector<int> v;
        // target-nums[i], idx
        std::unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); ++i){
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size();++i){
            if(m.count(target-nums[i]) && m[target-nums[i]] != i){
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                return v;
            }
        }
        return v;
    }
};