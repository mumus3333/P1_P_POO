// Hexagon.h
#ifndef HEXAGON_H
#define HEXAGON_H

#include "Polygon.h"
#include <cmath>

// La clase Hexagon hereda de Polygon y representa un hexágono regular con 
// seis lados iguales. Implementa los métodos area() y perimeter(), utilizando 
// fórmulas específicas para polígonos regulares.
class Hexagon : public Polygon {
protected:
    double side;
public:
    Hexagon(double s) : side(s) {}
    double perimeter() const override {
        return 6 * side;
    }
    double area() const override {
        return (3 * std::sqrt(3) * side * side) / 2;
    }
};

#endif
