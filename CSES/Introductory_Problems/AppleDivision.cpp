#include <bits/stdc++.h>
using ll = long long;
ll n;
ll v[20];
ll recursion(ll index, ll sum_1, ll sum_2)
{
  if(index==n) return std::abs(sum_1-sum_2);
  return std::min(recursion(index+1,sum_1+v[index],sum_2), recursion(index+1,sum_1,sum_2+v[index]));
}
 
int main()
{
  std::cin >> n;
  for(int i  = 0; i < n; ++i)
  {
    ll val; std::cin >> val;
    v[i]=val;
  }
  std::cout << recursion(0,0,0);
}
