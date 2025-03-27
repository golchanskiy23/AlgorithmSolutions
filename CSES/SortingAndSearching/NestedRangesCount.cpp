#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template< typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
 
struct range
{
  ll left, right, index;
};
bool cmp(const range& r1, const range& r2)
{
  if(r1.left==r2.left)
    return r1.right > r2.right;
  return r1.left < r2.left;
}
 
int main()
{
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<range> vr;
  for(int i = 0; i < n; i++)
  {
    ll l, r;
    std::cin >> l >> r;
    vr.push_back({l,r,i});
  }
  std::sort(vr.begin(), vr.end(), cmp);
  std::vector<ll> contains(n), contained(n);
  ordered_set<std::pair<ll,ll>> set;
  for(ll i = 0; i < n; i++)
  {
    set.insert({vr[i].right, -1*i});
    contained[vr[i].index] = set.size()-set.order_of_key({vr[i].right,-1*i})-1;
  }
  set.clear();
  for(ll i = n-1; i >= 0; i--)
  {
    set.insert({vr[i].right, -1*i});
    contains[vr[i].index] = set.order_of_key({vr[i].right,-1*i});
  }
 
 
 
  for(int i = 0; i < n; i++)
    std::cout << (int)contains[i] << " ";
  std::cout << '\n';
  for(int i = 0; i < n; i++)
    std::cout << (int)contained[i] << " ";
}