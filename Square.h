// Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

// La clase Square hereda de Rectangle y representa un cuadrado, que tiene 
// cuatro lados iguales. Utiliza los métodos heredados de Rectangle para 
// calcular el área y el perímetro.
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
};

#endif
