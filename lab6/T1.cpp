//
// Created by chujoy on 23.02.2026.
//
#include "T1.h"
void t1() {
    int n;
    std::cout << "How many shapes do you want to enter? ";
    do {
        std::cin >> n;
    }while (n <1);
    Shape* shapes = new Shape[n];

    for (int i = 0; i < n; ++i) {
        shapes[i] = inputShape(i + 1);
    }

    std::string filename;
    std::cout << "\nEnter filename: ";
    std::cin >> filename;

    saveToFile(shapes, n, filename);
    printTable(shapes, n);

    delete[] shapes;
}
std::string shapeTypeName(ShapeType t) {
    switch (t) {
        case CIRCLE:  return "Circle";
        case SQUARE:  return "Square";
        case SEGMENT: return "Segment";
    }
    return "grievous error";
}

std::string dimensionStr(const Shape& s) {
    switch (s.type) {
        case CIRCLE:  return std::to_string((int)s.dim.radius);
        case SQUARE:  return std::to_string(s.dim.side);
        case SEGMENT: {
            // float with 2 decimal places
            char buf[32];
            std::snprintf(buf, sizeof(buf), "%.2f", s.dim.segLength);
            return std::string(buf);
        }
    }
    return "-";
}

std::string dimensionLabel(const Shape& s) {
    switch (s.type) {
        case CIRCLE:  return "Radius";
        case SQUARE:  return "Side";
        case SEGMENT: return "Length";
    }
    return "-";
}

Shape inputShape(int index) {
    Shape s;
    int choice;

    std::cout << "\n--- Shape #" << index << " ---\n";

    std::cout << "Select shape type:\n"
              << "  0 - Circle\n"
              << "  1 - Square\n"
              << "  2 - Line Segment\n"
              << "Choice: ";
    do {
        std::cin >> choice;
    }while (choice<0 || choice > 2);
    s.type = static_cast<ShapeType>(choice);

    std::cout << "Enter color: ";
    std::string colour;
    std::cin  >> colour;
    s.color = colour;

    switch (s.type) {
        case CIRCLE: {
            short int r;
            std::cout << "Enter radius (short int, > 0): ";
            do {
                std::cin >> r;
            }while (r < 1);
            s.dim.radius = r;
            break;
        }
        case SQUARE: {
            int side;
            std::cout << "Enter side length (int, > 0): ";
            do {
                std::cin >> side;
            }while (side < 1);
            s.dim.side = side;
            break;
        }
        case SEGMENT: {
            float len;
            std::cout << "Enter segment length (float, > 0): ";
            do {
                std::cin >> len;
            }while (len <= 0);
            s.dim.segLength = len;
            break;
        }
    }
    return s;
}

void saveToFile(const Shape* shapes, int n, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Error: could not open " << filename << " for writing.\n";
        return;
    }

    out << n << "\n";
    for (int i = 0; i < n; ++i) {
        out << shapes[i].type << " " << shapes[i].color << " ";
        switch (shapes[i].type) {
            case CIRCLE:  out << shapes[i].dim.radius;    break;
            case SQUARE:  out << shapes[i].dim.side;      break;
            case SEGMENT: out << shapes[i].dim.segLength; break;
        }
        out << "\n";
    }

    std::cout << "\nData saved to " << filename << "\n";
}

void printTable(const Shape* shapes, int n) {
    const int W_IDX   = 6;
    const int W_TYPE  = 10;
    const int W_COLOR = 8;
    const int W_DIM_L = 10;
    const int W_DIM_V = 10;

    std::string sep(W_IDX + W_TYPE + W_COLOR + W_DIM_L + W_DIM_V + 6, '-');

    std::cout << "\n" << sep << "\n";
    std::cout << std::left
    << std::setw(W_IDX)   << "| #"
    << std::setw(W_TYPE)  << "| Type"
    << std::setw(W_COLOR) << "| Color"
    << std::setw(W_DIM_L) << "| Measure"
    << std::setw(W_DIM_V) << "| Value"
    << "|\n";
    std::cout << sep << "\n";

    for (int i = 0; i < n; ++i) {
        std::cout << std::left
        << "| " << std::setw(W_IDX - 2)   << (i + 1)
        << "| " << std::setw(W_TYPE - 2)  << shapeTypeName(shapes[i].type)
        << "| " << std::setw(W_COLOR - 2) << shapes[i].color
        << "| " << std::setw(W_DIM_L - 2) << dimensionLabel(shapes[i])
        << "| " << std::setw(W_DIM_V - 2) << dimensionStr(shapes[i])
        << "|\n";
    }

    std::cout << sep << "\n";
}
