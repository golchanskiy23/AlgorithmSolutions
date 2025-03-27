#include <bits/stdc++.h>
using ll = long long;
 
#include <bits/stdc++.h>
 
void findFourElements(ll arr[], ll n, ll X)
{
  std::unordered_map<ll, std::pair<ll, ll> > mp;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      mp[arr[i] + arr[j]] = { i, j };
 
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      ll sum = arr[i] + arr[j];
 
      if (mp.find(X - sum) != mp.end())
      {
        std::pair<ll, ll> p = mp[X - sum];
        if (p.first != i && p.first != j
            && p.second != i && p.second != j)
        {
          std::cout << i+1 << " " << j+1 << " " << p.first+1 << " " << p.second+1;
          return;
        }
      }
    }
  }
  std::cout << "IMPOSSIBLE";
}
 
int main()
{
  ll n, target;
  std::cin >> n >> target;
  ll arr[n];
  for(int i = 0; i < n; i++)
    std::cin >> arr[i];
  findFourElements(arr, n, target);
  return 0;
}
