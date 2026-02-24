#include <iostream>
#include <vector>
#include "array_io.h"
void m29()
{
    std::cout << "Matrix29. Enter n and m: ";
    int y,x;
    do {
        std::cin >> y >> x;
    }while (y < 1 || x < 1);
    std::cout << '\n';
    const int m = x;
    const int n = y;
    std::vector<std::vector<int>> a(m, std::vector<int>(n));
    arrinput(n, m, a);
    //do stuff
    int* medar = new int[n];
    int* counter = new int[n];
    for (int i = 0; i < n; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            medar[i] += a[i][j];
        }
        medar[i] /= n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < medar[i]) {
                counter[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << i+1 << '\t' << counter[i] << "\t\n";
    }
}
