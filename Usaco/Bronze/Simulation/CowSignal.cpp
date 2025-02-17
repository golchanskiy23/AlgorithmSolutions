#include <iostream>
#include <vector>

void task3(){
    freopen("cowsignal.in", "r", stdin);
    int m,n,k;
    std::cin >> m >> n >> k;
    std::vector<std::vector<char>> start(m, std::vector<char>(n));
    std::vector<std::vector<char>> end(k*m, std::vector<char>(k*n));
    for(int i = 0; i  < m;++i){
        for(int j = 0; j < n; ++j){
            std::cin >> start[i][j];
        }
    }
    int i = 0, j = 0;
    for (int i = 0; i < m; ++i) {   // Перебираем строки оригинала
        for (int j = 0; j < n; ++j) { // Перебираем столбцы оригинала
            char value = start[i][j]; // Значение текущего элемента
            for (int a = 0; a < k; ++a) { // Увеличение в высоту
                for (int b = 0; b < k; ++b) { // Увеличение в ширину
                    end[i * k + a][j * k + b] = value;
                }
            }
        }
    }
    freopen("cowsignal.out", "w", stdout);
    for(auto& a : end){
        for(auto& b : a){
            std::cout << b;
        }
        std::cout << '\n';
    }
}

int main()
{
    task3();
    return 0;
}