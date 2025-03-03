class Solution {
public:
    int trap(vector<int>& height) {
        int left =  0, right = height.size()-1;
        int l_max = 0, r_max = 0, ans=  0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= l_max){
                    l_max = height[left];
                }
                else ans += (l_max-height[left]);
                ++left;
            }
            else{
                if(height[right] >= r_max){
                    r_max = height[right];
                }
                else ans += (r_max-height[right]);
                --right;
            }
        }
        return ans;
    }
};