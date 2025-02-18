class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        std::vector<int> diff(n);
        for(int i = 0; i < n; ++i){
            diff[i] = (gas[i]-cost[i]);
        }
        int i = n-1, j=n-1, cnt=0, tank = 0;
        while(cnt < n){
            tank += diff[j];
            cnt++;
            j = (j+1)%n;
            while(tank < 0 && cnt < n){
                i--;
                tank += diff[i];
                cnt++;
            }
        }
        if (tank < 0) return -1;
        return i;
    }
};