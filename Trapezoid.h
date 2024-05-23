#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Quadrilateral.h"
#include <cmath>

// La clase Trapezoid hereda de Quadrilateral y representa un trapecio.
class Trapezoid : public Quadrilateral {
private:
    double height;
public:
    Trapezoid(double s1, double s2, double s3, double s4, double h) 
        : Quadrilateral(s1, s2, s3, s4), height(h) {}

    double area() const override {
        double a = side1;
        double b = side2;
        double c = side3;
        double d = side4;

        // Utilizando una fórmula general para el área de un trapecio
        double semiPerimeter = (a + b + c + d) / 2;
        double area = (a + b) / std::abs(a - b) *
                      std::sqrt((semiPerimeter - a) * (semiPerimeter - b) *
                                (semiPerimeter - a - c) * (semiPerimeter - a - d));
        return area;
    }
};

#endif // TRAPEZOID_H
