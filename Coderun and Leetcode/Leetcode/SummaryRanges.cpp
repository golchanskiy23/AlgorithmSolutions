class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> v;
        if(n == 0) return v;
        vector<long> pref(n-1);
        for(int i = 1; i < n; ++i){
            pref[i-1] = (long)nums[i]-(long)nums[i-1];
        }
        
        int curr = nums[0], end = curr;
        for(int i = 0; i < pref.size(); ++i){
            if(pref[i] != 1){
                string currStr;
                if(curr == end) currStr = std::to_string(curr);
                else currStr = std::to_string(curr)+"->"+std::to_string(end);
                v.push_back(currStr);
                curr = end+pref[i];
                end = curr;
            }
            else{
                ++end;
            }
        }
        string currStr;
        if(curr == end) currStr = std::to_string(curr);
        else currStr = std::to_string(curr)+"->"+std::to_string(end);
        v.push_back(currStr);
        return v;
    }
};