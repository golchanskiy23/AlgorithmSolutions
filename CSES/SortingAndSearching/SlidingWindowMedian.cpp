#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
template<typename T>
using ordered_set = tree <T,null_type,std::less<T>,rb_tree_tag,tree_order_statistics_node_update >;
 
int main()
{
  ll n, k;
  std::cin >> n >> k;
  std::vector<ll> v(n);
  for(auto& a : v)
    std::cin >> a;
  ordered_set<std::pair<ll,ll>> os;
  for(int i = 0; i < k; i++)
  {
    os.insert({v[i],i});
  }
  std::cout << os.find_by_order((k-1)/2)->first << " ";
  for(ll i = 1; i < n-k+1; i++)
  {
    os.erase({v[i-1],i-1});
    os.insert({v[i+k-1], i+k-1});
    std::cout << os.find_by_order((k-1)/2)->first << " ";
  }
}