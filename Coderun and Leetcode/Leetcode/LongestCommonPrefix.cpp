class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // size/appearance
        std::map<std::string, std::pair<int,int>> m;
        for(int i = 0; i < strs.size(); ++i){
            for(int j = 0; j < strs[i].size(); ++j){
                std::string curr =  strs[i].substr(0,j+1);
                m[curr].first = (int)curr.size();
                m[curr].second++;
            }
        }
        int max_size = 1;
        std::string curr_str = "";
        for(auto& a : m){
            //std::cout << a.first << " " << a.second.first << " " << a.second.second << '\n';
            if(max_size <= a.second.first && a.second.second == strs.size()){
                max_size = a.second.first;
                curr_str = a.first;
            }
        }
        return curr_str;
    }
};