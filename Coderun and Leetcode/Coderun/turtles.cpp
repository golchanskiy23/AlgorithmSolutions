#include <iostream>
#include <string>
#include <vector>

int main() 
{
	int n,cnt = 0; std::cin >> n;
    std::vector<int> pos(n+1,-1);
    for(int i = 0; i < n; ++i){
        int a,b; std::cin >> a >> b;
        if(a+1 == n-b && a+1 <= n && pos[a+1] == -1){
            pos[a+1] = 1;
            cnt++;
        }
    }
    std::cout << cnt;

	return 0;
}