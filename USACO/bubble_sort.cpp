#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countSwaps' function below.
 *
 * The function accepts INTEGER_ARRAY a as parameter.
 */
 
int bubble_sort(std::vector<int>& a); 
void countSwaps(std::vector<int> a);
 
int bubble_sort(std::vector<int>& a){
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i){
        for(int j = i; j < a.size(); ++j){
            if(a[j] < a[i] ) {
                std::swap(a[i],a[j]);
                cnt++;
        }
    }
    }
    return cnt;
}

void countSwaps(vector<int> a) {
    int sort_ = bubble_sort(a);
    std::cout << "Array is sorted in " << sort_ <<  " swaps." << '\n';

    std::cout << "First Element: " << a[0] << '\n';

    std::cout << "Last Element: " << a[a.size()-1] << '\n';
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
