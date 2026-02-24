
#include <iostream>
#include <vector>
#include <bits/shared_ptr_base.h>

#include "array_io.h"
void m59()
{
    std::cout << "Matrix59. Enter n and m: ";
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
    //ig we have a temp thing  & a counter
    int counter = n-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::swap(a[i][j], a[counter][j]);
        }
        counter--;
    }
    arroutput(n, m, a);
}