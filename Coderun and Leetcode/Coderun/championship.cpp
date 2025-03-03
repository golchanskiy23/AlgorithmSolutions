#include <iostream>
#include <vector>
using namespace std;

int findWinnerPlace(const vector<int>& array) {
    int n = array.size();
    int bestScore = array[0];
    bool found = false;
    int vasiliyScore = 0;

    for (int i = 1; i < n - 1; i++) {
        int tempScore = array[i];
        
        if (tempScore > bestScore) {
            bestScore = tempScore;
            found = false;
        }
        else if ((tempScore % 10 == 5) && tempScore > array[i + 1]) {
            if (!found || tempScore > vasiliyScore) {
                vasiliyScore = tempScore;
                found = true;
            }
        }
    }

    if (!found) return 0;

    int place = 1;
    for (int score : array) {
        if (score > vasiliyScore) {
            place++;
        }
    }
    return place;
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    cout << findWinnerPlace(array) << endl;
    return 0;
}
