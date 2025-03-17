#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    priority_queue<int, vector<int>, greater<int>> freeTracks;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busyTracks;

    for (int i = 1; i <= k; i++) freeTracks.push(i);
    vector<int> ans;

    for (int trainIdx = 1; trainIdx <= n; trainIdx++) {
        int arrival, departure;
        cin >> arrival >> departure;

        while (!busyTracks.empty() && busyTracks.top().first < arrival) {
            freeTracks.push(busyTracks.top().second);
            busyTracks.pop();
        }

        if (!freeTracks.empty()) {
            int track = freeTracks.top();
            freeTracks.pop();
            busyTracks.push({departure, track});
            ans.push_back(track);
        }
        else {
            cout << "0 " << trainIdx << '\n';
            return 0;
        }
    }
    
    for(auto& a : ans) std::cout << a << '\n';

    return 0;
}