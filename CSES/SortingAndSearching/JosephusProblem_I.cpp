#include <bits/stdc++.h>
using ll = long long;
 
/*void Josephus_problem(std::vector<ll>& v, ll index, ll miss)
{
  if(v.size()==1)
  {
    std::cout << v[0] << " ";
    return;
  }
  std::cout << v[index] << " ";
  v.erase(v.begin() + index);
  index = (index + miss) % v.size();
  Josephus_problem(v,index, miss);
}*/
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> v;
  for(int i = 1; i <= n; i++)
    v.push_back(i);
  while(v.size() > 0)
  {
    std::deque<ll> tmp;
    std::vector<ll> out_vector;
    for(int i = 0; i < v.size(); i++)
    {
      (i%2 == 0) ? tmp.push_back(v[i]) : (out_vector.push_back(v[i]));
    }
    for(auto& a : out_vector)
      std::cout << a << " ";
    if(tmp[0]==0)
      tmp.pop_front();
    if(tmp.size()==1)
    {
      std::cout << tmp[0];
      break;
    }
    if(v.size()%2==0)
    {
      v.clear();
      for(auto& a : tmp)
        v.push_back(a);
    }
    else
    {
      tmp.push_front(0);
      v.clear();
      for(auto& a : tmp)
        v.push_back(a);
    }
 
  }
 
  /*ll n,k;
  std::cin >> n >> k;
  std::vector<ll> v;
  for(int i = 1; i <= n; i++)
    v.push_back(i);
  Josephus_problem(v,1,k);*/
}
