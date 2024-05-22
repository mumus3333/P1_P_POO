// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"
#include <cmath>

// La clase Triangle hereda de Polygon y representa un triángulo genérico. 
// Tiene tres lados (side1, side2, side3) y proporciona implementaciones 
// específicas para los métodos area() y perimeter(). El área se calcula 
// utilizando la fórmula de Herón.
class Triangle : public Polygon {
protected:
    double side1, side2, side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    double perimeter() const override {
        return side1 + side2 + side3;
    }
    double area() const override {
        double s = perimeter() / 2;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

#endif
