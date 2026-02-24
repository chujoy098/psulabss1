#include <iostream>
#include <vector>
#include "array_io.h"
void d16()
{
    std::cout << "DArray16. Enter n and m: ";
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
    bool condflag = false;
    for (int i = 0; i < n; i++) {
        if (condflag)
        {break;}
        for (int j = 0; j < m; j++) {
            if (condflag)
            {break;}
            if ( i > 0 && j > 0 && i < x-- && j < y--) {
                if ( a[i][j] == a[i+1][j+1] + a[i-1][j-1] + a[i+1][j-1] + a[i-1][j+1])
                {condflag = true;}
            }
        }
    }
    if (condflag) {
        std::cout << "There is a number which is equal to the sum of it's neighbours.\n";
    }
    else {
        std::cout << "No...\n";
    }
}