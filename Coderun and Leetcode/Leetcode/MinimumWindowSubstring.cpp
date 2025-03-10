class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, formed = 0, minWindow = INT_MAX, startIdx = 0;
        std::unordered_map<char,int> s_map, t_map;
        for(auto& a : t) t_map[a]++;

        while(r < s.size()){
            char c = s[r];
            s_map[c]++;

            if(t_map.count(c) && s_map[c] == t_map[c]){
                formed++;
            }

            while(l <= r && formed == t_map.size()){
                if(r-l+1 < minWindow){
                    minWindow = r-l+1;
                    startIdx = l;
                }

                c = s[l];
                s_map[c]--;
                if(t_map.count(c) && s_map[c] < t_map[c]){
                    formed--;
                }
                l++;
            }
            r++;
        }
        return (minWindow == INT_MAX) ? "" : s.substr(startIdx, minWindow);
    }
};