class Solution {
public:
    int maxArea(vector<int>& v) {
        int l = 0, r = v.size()-1, maxSquare = std::min(v[l], v[r])*(r-l);
        while(l < r){
            if(v[l] < v[r]) ++l;
            else --r;
            maxSquare = std::max(maxSquare, (r-l)*std::min(v[r],v[l]));
        }
        return maxSquare;
    }
};