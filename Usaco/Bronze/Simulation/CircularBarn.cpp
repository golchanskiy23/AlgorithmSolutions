#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>



int main()
{
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int n; std::cin >> n;
    std::vector<int> v(n);
    int ans = INT_MAX, summ=0;
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
        summ += v[i];
    }
    for(int i = 0; i < n; ++i){
        int reps = 1, curr_idx = i, cows = summ, curr_sum = 0;
        while(reps < n){
            cows -= v[curr_idx];
            curr_sum += cows;
            curr_idx = (curr_idx+1)%n;
            ++reps;
        }
        ans = std::min(ans,curr_sum);
    }
    std::cout << ans;

    return 0;
}