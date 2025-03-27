#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
    ll n;
    std::cin >> n;
    std::vector<ll> v(n);
    for(auto& a : v)
    {
        std::cin >> a;
    }
    ll left = 0, right = 0, ans = 0;
    std::set<ll> set;
    while(right < n && left < n)
    {
        while(right < n && !set.count(v[right]))
        {
            set.insert(v[right]);
            ans = std::max(ans, right-left+1);
            ++right;
        }
        while(right < n && set.count(v[right]))
        {
            set.erase(v[left]);
            ++left;
        }
    }
    std::cout << ans;
}
