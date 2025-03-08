class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;
        for(auto& a : strs){
            auto sorted = a;
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(a);
        }
        for(auto& a : m){
            ans.push_back(a.second);
        }
        return ans;
    }
};