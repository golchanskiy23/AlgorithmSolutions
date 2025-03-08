class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
        int n = vec.size(), l = 0, r = n-1;
        std::vector<int> v(2);
        while(true){
            if(vec[l] + vec[r] > target) r--;
            else if(vec[l] + vec[r] < target) l++;
            else {
                v[0] = l+1; v[1] = r+1;
                return v;
            }
        }
        return v;
    }
};