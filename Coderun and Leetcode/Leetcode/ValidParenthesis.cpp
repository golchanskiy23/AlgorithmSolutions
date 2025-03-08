class Solution {
public:
    bool isValid(string s) {
        map<char,char> m{{'(',')'}, {'[',']'}, {'{','}'}};
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(!st.empty() && s[i] == m[st.top()]){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};