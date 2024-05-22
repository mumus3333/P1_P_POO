// Polygon.h
#ifndef POLYGON_H
#define POLYGON_H

// La clase abstracta Polygon define la interfaz para todos los tipos de polígonos. 
// Declara dos métodos virtuales puros: area() y perimeter(), que deben ser 
// implementados por cualquier clase derivada. Esto asegura que cualquier polígono 
// tendrá métodos para calcular su área y perímetro.
class Polygon {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Polygon() {}
};

#endif
