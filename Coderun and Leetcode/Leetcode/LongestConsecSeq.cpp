class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int currLength = 0, maxLength = 0, currNumber = 0, n = nums.size(), theBiggest = -2*1000000000;
        if(n == 0) return 0;
        map<int, int> m;
        for(auto& a : nums){
            theBiggest = std::max(theBiggest, a);
            m[a]++;
        }

        for(auto& a : m){
            if(currLength == 0) {
                currNumber = a.first;
                currLength = 1;
            } else{
            if(m[currNumber+1]){
                    ++currNumber;
                    ++currLength;
                }
                else{
                    currLength = 1;
                    currNumber = a.first;
                }
            }
            maxLength = std::max(maxLength, currLength);
        }
        return maxLength;
    }
};