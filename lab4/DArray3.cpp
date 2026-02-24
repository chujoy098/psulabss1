#include <iostream>
#include <vector>
#include "array_io.h"
void d3()
{
    std::cout << "Darray3. Enter n ";
    int y;
    do {
        std::cin >> y;
    }while (y < 1);
    std::cout << '\n';
    const int n = y;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    arrinput(n, n, a);
    //do stuff
    int* sumab = new int[n];
    int* sumbe = new int[n];
    for (int i = 0; i < n; i++) {
        sumab[i] = 0;
        sumbe[i] = 0;
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j+counter++ < n) {
                sumbe[i] += a[i][j+counter++];
            }
            if (counter-j-- >=0) {
                sumab[i] += a[i][counter-j--];
            }
        }
        counter++;
    }
    arroutput(n, n, a);
}