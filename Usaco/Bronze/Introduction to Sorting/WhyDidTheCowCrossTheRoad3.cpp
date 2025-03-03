#include <bits/stdc++.h>

int main(){
  std::ifstream in("cowqueue.in");
  std::ofstream out("cowqueue.out");
  int n; in >> n;
  std::vector<std::pair<int,int>> v(n);
  for(int i = 0; i < n; ++i){
    int a,b; in >> a >> b;
    v[i] = std::make_pair(a,b);
  }
  std::sort(v.begin(), v.end(), [](std::pair<int,int>& p1, std::pair<int,int>& p2){
    return p1.first < p2.first;
  });
  int start = 0, end = 0;
  for(int i = 0; i < n; ++i){
    if(v[i].first >= end){
      start = v[i].first;
    }
    else{
      start = end;
    }
    end = start + v[i].second;
  }
  out << end;
}