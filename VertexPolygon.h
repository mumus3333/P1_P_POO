#ifndef VERTEXPOLYGON_H
#define VERTEXPOLYGON_H

#include "Polygon.h"
#include <vector>
#include <cmath>

using namespace std; // Agregando el using namespace std

class VertexPolygon : public Polygon {
private:
    vector<pair<double, double>> vertices; // Vértices del polígono

    // Método auxiliar para calcular la distancia entre dos puntos
    double distance(const pair<double, double>& p1, const pair<double, double>& p2) const {
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    }

    // Método auxiliar para comparar dos valores de punto flotante con tolerancia
    bool isEqual(double a, double b, double epsilon = 1e-6) const {
        return abs(a - b) < epsilon;
    }

public:
    VertexPolygon(const vector<pair<double, double>>& verts) : vertices(verts) {}

    // Calcula el perímetro sumando las distancias entre vértices consecutivos
    double perimeter() const override {
        double peri = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            peri += distance(vertices[i], vertices[(i + 1) % vertices.size()]);
        }
        return peri;
    }

    // Calcula el área utilizando la fórmula del área del polígono basado en coordenadas
    double area() const override {
        double a = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const auto& p1 = vertices[i];
            const auto& p2 = vertices[(i + 1) % vertices.size()];
            a += p1.first * p2.second - p1.second * p2.first;
        }
        return abs(a) / 2.0;
    }

    // Método para verificar si dos polígonos son similares
    bool isSimilarTo(const VertexPolygon& other) const {
        if (vertices.size() != other.vertices.size()) {
            return false;
        }
        // Verificar la proporcionalidad de los lados
        double perimeter1 = perimeter();
        double perimeter2 = other.perimeter();
        double ratio = perimeter1 / perimeter2;

        for (size_t i = 0; i < vertices.size(); ++i) {
            double side1 = distance(vertices[i], vertices[(i + 1) % vertices.size()]);
            double side2 = other.distance(other.vertices[i], other.vertices[(i + 1) % other.vertices.size()]);
            if (!isEqual(side1 / side2, ratio)) {
                return false;
            }
        }

        return true;
    }
};

#endif
