// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Quadrilateral.h"

// La clase Rectangle hereda de Quadrilateral y representa un rectángulo, 
// que tiene lados opuestos iguales. Implementa el método area() para calcular 
// el área del rectángulo.
class Rectangle : public Quadrilateral {
public:
    Rectangle(double width, double height) 
        : Quadrilateral(width, height, width, height) {}
    double area() const override {
        return side1 * side2;
    }
};

#endif
