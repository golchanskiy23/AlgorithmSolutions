class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int n = citations.size();
        
        int cnt = 1;
        for(int i = 0; i < n; i++){
            if(citations[n-1-i] < cnt) return cnt-1;
            cnt++;
        }
        return n;
    }
};