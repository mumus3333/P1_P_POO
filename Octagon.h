// Octagon.h
#ifndef OCTAGON_H
#define OCTAGON_H

#include "Polygon.h"
#include <cmath>

// La clase Octagon hereda de Polygon y representa un octágono regular con 
// ocho lados iguales. Implementa los métodos area() y perimeter(), utilizando 
// fórmulas específicas para polígonos regulares.
class Octagon : public Polygon {
protected:
    double side;
public:
    Octagon(double s) : side(s) {}
    double perimeter() const override {
        return 8 * side;
    }
    double area() const override {
        return 2 * (1 + std::sqrt(2)) * side * side;
    }
};

#endif
