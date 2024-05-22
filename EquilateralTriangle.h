// EquilateralTriangle.h
#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "Triangle.h"

// La clase EquilateralTriangle hereda de Triangle y representa un triángulo 
// equilátero, que tiene tres lados iguales. Utiliza los métodos heredados 
// de Triangle para calcular el área y el perímetro.
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) 
        : Triangle(side, side, side) {}
};

#endif
