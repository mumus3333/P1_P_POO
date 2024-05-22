// Quadrilateral.h
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Polygon.h"

// La clase Quadrilateral hereda de Polygon y representa un cuadrilátero genérico 
// con cuatro lados (side1, side2, side3, side4). Proporciona una implementación 
// para el método perimeter(), pero deja la implementación de area() para las 
// clases derivadas, ya que el cálculo del área puede variar dependiendo del tipo de cuadrilátero.
class Quadrilateral : public Polygon {
protected:
    double side1, side2, side3, side4;
public:
    Quadrilateral(double s1, double s2, double s3, double s4) 
        : side1(s1), side2(s2), side3(s3), side4(s4) {}
    double perimeter() const override {
        return side1 + side2 + side3 + side4;
    }
    virtual double area() const = 0; // To be implemented by derived classes
};

#endif
