#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,m;
  std::cin >> n >> m;
  std::vector<ll> v(n+1);
  std::vector<ll> pos(n+1);
  for(int i = 1; i < n+1; i++)
  {
    std::cin >> v[i];
    pos[v[i]] = i;
  }
  ll count = 1;
  for(int k = 1; k < n; k++)
  {
    if(pos[k+1]<pos[k]) ++count;
  }
 
  std::set<std::pair<ll,ll>> set;
  while(m--)
  {
    ll l,r;
    std::cin >> l >> r;
    if(v[l] <= n-1)
    {
      set.insert({v[l],v[l]+1});
    }
    if(v[r] <= n-1)
    {
      set.insert({v[r],v[r]+1});
    }
    if(v[l] >= 2)
    {
      set.insert({v[l]-1,v[l]});
    }
    if(v[r] >= 2)
    {
      set.insert({v[r]-1,v[r]});
    }
    for(auto& a : set)
    {
      if(pos[a.first]>pos[a.second])
      {
        count--;
      }
    }
    std::swap(v[r],v[l]);
    pos[v[l]] = l;
    pos[v[r]] = r;
    for(auto& a : set)
    {
      if(pos[a.first]>pos[a.second])
      {
        count++;
      }
    }
    std::cout << count << '\n';
    set.clear();
  }
}