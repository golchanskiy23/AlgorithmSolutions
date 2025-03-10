class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> pq;
        for(auto& a : nums) pq.push(a);
        int target = k, curr = 1;
        while(!pq.empty() && target != curr){
            pq.pop();
            ++curr;
        }
        return pq.top();
    }
};