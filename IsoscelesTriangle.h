// IsoscelesTriangle.h
#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Triangle.h"

// La clase IsoscelesTriangle hereda de Triangle y representa un triángulo 
// isósceles, que tiene dos lados iguales y una base. Utiliza los métodos 
// heredados de Triangle para calcular el área y el perímetro.
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double equalSide, double base) 
        : Triangle(equalSide, equalSide, base) {}
};

#endif
