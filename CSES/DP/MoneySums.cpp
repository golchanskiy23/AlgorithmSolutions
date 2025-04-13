#include <bits/stdc++.h>

std::vector<int> dp(100005);
bool visited[101][100005];
int count =0;

void dfs(int pos, const std::vector<int>& arr, int sum) {
    if (visited[pos][sum]) return;
    visited[pos][sum] = true;
    
    if(dp[sum] == 0){
        dp[sum] = 1;
        count++;
    }
    
    for(int i = pos; i < arr.size(); i++){
        sum += arr[i];
        //std::cout << i << " " << sum << '\n';
        dfs(i+1, arr, sum);
        sum -= arr[i];
    }
}

int main(){
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    for(int i = 0; i < n; i++){
        dfs(i, arr, 0);
    }
    
    std::cout << count-1 << '\n';
    for(int i = 0; i <= 100004; i++){
        if(dp[i] != 0 && i != 0) std::cout << i << " ";
    }
}