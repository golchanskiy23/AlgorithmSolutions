#include <bits/stdc++.h>
using ll = long long;
 
const ll MAX_N = 2e5;
 
ll N;
ll ans[MAX_N];
std::vector<std::pair<std::pair<ll, ll>, ll>> v(MAX_N);
 
int main() {
  std::cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i; // store the original index
  }
  sort(v.begin(), v.end());
 
  ll rooms = 0, last_room = 0;
  std::priority_queue<std::pair<int, int>> pq; // min heap to store departure times.
  for (int i = 0; i < N; i++) {
    if (pq.empty()) {
      last_room++;
      // make the departure time negative so that we create a min heap
      // (cleanest way to do a min heap... default is max in c++)
      pq.push(std::make_pair(-v[i].first.second, last_room));
      ans[v[i].second] = last_room;
    }
    else {
      // accessing the minimum departure time
      std::pair<ll, ll> minimum = pq.top();
      if (-minimum.first < v[i].first.first) {
        pq.pop();
        pq.push(std::make_pair(-v[i].first.second, minimum.second));
        ans[v[i].second] = minimum.second;
      }
 
      else {
        last_room++;
        pq.push(std::make_pair(-v[i].first.second, last_room));
        ans[v[i].second] = last_room;
      }
    }
 
    rooms = std::max(rooms, ll(pq.size()));
  }
 
 
  std::cout << rooms << "\n";
  for (int i = 0; i < N; i++) {
    std::cout << ans[i] << " ";
  }
}
 
 
/*struct apartment
{
  ll arrival, departure, room;
  apartment(ll arr, ll dep, ll room)
  {
    arrival = arr;
    departure = dep;
    room = room;
  }
};
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<apartment> v;
  for(int i = 0; i < n; i++)
  {
    ll arrival, departure;
    std::cin >> arrival >> departure;
    v.push_back(apartment(arrival, departure, i));
  }
  std::sort(v.begin(), v.end(), [](const apartment& app1,const apartment& app2){
    if(app1.arrival == app2.arrival)
      return app1.departure < app2.departure;
    return app1.arrival < app2.arrival;
  });
  ll last_number = 0, total = 0;
  ll numbers[n+1];
  std::priority_queue<std::pair<ll,ll>> pq;
  for(auto& a : v)
  {
    if(pq.empty())
    {
      ++last_number;
      pq.push(std::make_pair(-a.departure,last_number));
      numbers[a.room] = last_number;
    }
    else
    {
      auto top_element = pq.top();
      if(-top_element.first < a.arrival)
      {
        pq.pop();
        pq.push(std::make_pair(-a.departure,top_element.second));
        numbers[a.room] = top_element.second;
      }
      else
      {
        ++last_number;
        pq.push(std::make_pair(-a.departure, last_number));
        numbers[a.room] = last_number;
      }
    }
    total = std::max(total, (ll)pq.size());
  }
  std::cout << total << '\n';
  for(auto& a : numbers)
    std::cout << a << " ";
}*/