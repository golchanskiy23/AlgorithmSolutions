class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& v1, const std::vector<int>& v2){
            if(v1[0] == v2[0]) return v1[1] < v2[1];
            return v1[0] < v2[0];
        });
        int start = intervals[0][0], end = intervals[0][1];
        std::vector<std::vector<int>> ans;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= end){
                if(intervals[i][1] > end) end = intervals[i][1];
            }
            else{
                std::vector<int> v;
                v.push_back(start);
                v.push_back(end);
                ans.push_back(v);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        if(ans.empty() || ans[ans.size()-1][1] != intervals[intervals.size()-1][1]){
            std::vector<int> v;
                v.push_back(start);
                v.push_back(end);
                ans.push_back(v);
        }
        return ans;
    }
};