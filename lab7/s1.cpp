//
// Created by chujoy on 24.02.2026.
//

#include "s1.h"
void s1() {
    std::random_device rd;
    std::cout << "Enter N: ";
    int n;
    do {
        std::cin>>n;
    }while (n<1);
    std::cout << "Enter amount of elements: ";
    int size;
    do {
        std::cin>>size;
    }while (size<1);
    int* arr = new int[size];
    for (int i=0; i<size; i++) {
        arr[i] = rd() % 255;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::ofstream outfile;
    outfile.open("output.txt");
    if (!outfile.is_open()) {
        std::cout << "Error opening output file\n";
        delete [] arr;
        return;
    }
    bubble_sort(arr, size, outfile);
    outfile.close();
    delete [] arr;
}
void bubble_sort(int* a, int n, std::ofstream& out) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
                std::string st1 = std::to_string(j);
                std::string st2 = std::to_string(j+1);
                out << "Element " << st1 << " swapped with " << st2 << "\n";
            }
            std::cout << a[j] << " ";
            if (j == i)
            {std::cout << "| ";}
        }
    }
}