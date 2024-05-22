// Pentagon.h
#ifndef PENTAGON_H
#define PENTAGON_H

#include "Polygon.h"
#include <cmath>

// La clase Pentagon hereda de Polygon y representa un pentágono regular con 
// cinco lados iguales. Implementa los métodos area() y perimeter(), utilizando 
// fórmulas específicas para polígonos regulares.
class Pentagon : public Polygon {
protected:
    double side;
public:
    Pentagon(double s) : side(s) {}
    double perimeter() const override {
        return 5 * side;
    }
    double area() const override {
        return (5 * side * side) / (4 * std::tan(M_PI / 5));
    }
};

#endif
