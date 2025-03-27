#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  std::string str;
  std::cin >> str;
  std::vector<int> v(26);
  for(int i = 0;  i < str.size(); i++)
    v[str[i] - 'A']++;
  ll count_of_chet = 0, count_of_nechet = 0;
  std::string string;
  for(auto& a : v)
  {
    if(a%2==0) count_of_chet++;
    else count_of_nechet++;
  }
  if(count_of_nechet>1)
    std::cout << "NO SOLUTION";
  else
  {
    for (int i = 0; i < 26; i++){
      if(!(v[i]%2)){
        for(int j = 0; j < v[i]/2; j++) string.push_back(i + 'A');
      }
    }
    for (int i = 0; i < 26; i++){
      if(v[i]%2){
        for(int j = 0; j < v[i]; j++) string.push_back(i + 'A');
      }
    }
    for (int i = 25; i >= 0; i--){
      if(!(v[i]%2)){
        for(int j = 0; j < v[i]/2; j++) string.push_back(i + 'A');
      }
    }
  }
  std::cout << string;
}