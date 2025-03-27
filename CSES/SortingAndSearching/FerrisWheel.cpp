#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,k, gondolas;
  std::cin >> n >> k;
  std::vector<ll> children(n);
  for(int i = 0; i < n;i++)
    std::cin >> children[i];
  std::sort(children.begin(), children.end());
  ll left = 0, right = n-1; gondolas = 0;
 
  while(left <= right)
  {
    if(children[left] + children[right] > k)
    {
      --right;
      ++gondolas;
    }
    else
    {
      ++left;
      --right;
      ++gondolas;
    }
  }
  std::cout << gondolas << '\n';
}
