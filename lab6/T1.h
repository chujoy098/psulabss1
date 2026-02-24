//
// Created by chujoy on 23.02.2026.
//

#ifndef LAB6_T1_H
#define LAB6_T1_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
enum ShapeType { CIRCLE, SQUARE, SEGMENT };
union Dimension {
    short int radius;      // for circle
    int       side;        // for square
    float     segLength;   // for line segment
};

struct Shape {
    ShapeType type;
    std::string color;
    Dimension dim;
};
void printTable(const Shape* shapes, int n);
void saveToFile(const Shape* shapes, int n, const std::string& filename);
Shape inputShape(int index);
std::string dimensionLabel(const Shape& s);
std::string dimensionStr(const Shape& s);
std::string shapeTypeName(ShapeType t);

#endif //LAB6_T1_H