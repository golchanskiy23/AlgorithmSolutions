class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), idx = n-1, spaces = 0;
        while(idx >= 0 && s[idx] == ' ') --idx;
        spaces = n-idx-1;
        while(idx >= 0 && s[idx] != ' ') --idx;
        return n-idx-1-spaces;
    }
};