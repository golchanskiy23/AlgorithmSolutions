class Solution {
public:
    bool isPalindrome(string s) {
        string newstring;
        for(int i = 0; i < s.size(); ++i){
            if(isalpha(s[i])) newstring += tolower(s[i]);
            if(isdigit(s[i])) newstring += s[i];
        }
        int l = 0, r = newstring.size()-1;
        while(l < r){
            if(newstring[l] != newstring[r]){return false;}
            --r;
            ++l;
        }
        return true;
    }
};