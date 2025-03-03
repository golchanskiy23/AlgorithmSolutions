class Solution {
public:
    // valuable / value
    std::map<char, std::pair<int,int>> m;
    void init(){
        m['I'] = std::make_pair(0,1);
        m['V'] = std::make_pair(1,5);
        m['X'] = std::make_pair(2,10);
        m['L'] = std::make_pair(3,50);
        m['C'] = std::make_pair(4,100);
        m['D'] = std::make_pair(5,500);
        m['M'] = std::make_pair(6,1000);
    }
    int romanToInt(string s) {
        int n = s.size(), curr_valuable = -1, ans = 0;
        init();
        for(int i = n-1; i >= 0; --i){
            if(m[s[i]].first < curr_valuable){
                ans -= m[s[i]].second;
            }
            else{
                ans += m[s[i]].second;
            }
            curr_valuable = m[s[i]].first;
        }
        return ans;
    }
};