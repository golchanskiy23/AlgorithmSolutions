#include <bits/stdc++.h>
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
  std::vector<bool> contains(n), contained(n);
  ll maximum = 1e12, minimum = 0;
  for(ll i = 0; i < n; i++)
  {
    if(vr[i].right <= minimum)
      contained[vr[i].index] = true;
    minimum = std::max(minimum, vr[i].right);
  }
  for(ll i = n-1; i >= 0; i--)
  {
    if(vr[i].right >= maximum)
      contains[vr[i].index] = true;
    maximum = std::min(maximum, vr[i].right);
  }
  for(int i = 0; i < n; i++)
    std::cout << (int)contains[i] << " ";
  std::cout << '\n';
  for(int i = 0; i < n; i++)
    std::cout << (int)contained[i] << " ";
}
