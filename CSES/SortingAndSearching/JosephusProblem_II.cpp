#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
template<typename T>
using ordered_set = tree <T,null_type,std::less<T>,rb_tree_tag,tree_order_statistics_node_update >;
 
int main()
{
  ll n,k;
  std::cin >> n >> k;
  ordered_set<ll> set;
  for (int i = 1; i <= n; i++)
    set.insert(i);
  ll index = 0;
  while (set.size() > 0)
  {
    index = (index + k) % set.size();
    auto it = set.find_by_order(index);
    std::cout << *it << " ";
    set.erase(it);
  }
}
