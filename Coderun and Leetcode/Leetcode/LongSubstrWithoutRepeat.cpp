class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size(), l=0,r = 0, max = 0;
        set<char> s;
        while(r < n){
            if(!s.count(str[r])){
                s.insert(str[r++]);
                max = std::max(max, (int)s.size());
            }
            else{
                while(l <= r && str[l] != str[r]) {
                    s.erase(str[l]);
                    l++;
                }
                s.erase(str[l++]);
            }
        }
        return max;
    }
};