#include <bits/stdc++.h>

int main(){
  std::ifstream in("circlecross.in");
  std::ofstream out("circlecross.out");

  std::vector<int> start(26,-1), end(26,-1);
  std::string str; in >> str;
  for(int i = 0; i < str.size(); ++i){
    if(start[str[i]-'A'] != -1) end[str[i]-'A'] = i;
    else{
      start[str[i]-'A'] = i;
    }
  }

  int ans = 0;
  for(int i = 0; i < 26; ++i){
    for(int j = 0; j < 26; ++j){
      if(start[i] < start[j] && end[i] < end[j] && start[j] < end[i]) ++ans;
    }
  }
  out << ans;
}