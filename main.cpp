// main.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include "Polygon.h"
#include "Triangle.h"
#include "Quadrilateral.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "VertexPolygon.h"

using namespace std;

// Función para crear polígonos definidos por vértices
void createVertexPolygon() {
    int numVertices;
    cout << "Ingrese el número de vértices del polígono:\n";
    cin >> numVertices;

    vector<pair<double, double>> vertices(numVertices);
    cout << "Ingrese las coordenadas de los vértices (x y):\n";
    for (int i = 0; i < numVertices; ++i) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    VertexPolygon polygon(vertices);
    cout << "Área: " << polygon.area() << "\n";
    cout << "Perímetro: " << polygon.perimeter() << "\n";
}

// Función para verificar si dos polígonos son similares
void checkSimilarity() {
    int numVertices;
    cout << "Ingrese el número de vértices de los polígonos:\n";
    cin >> numVertices;

    vector<pair<double, double>> vertices1(numVertices);
    vector<pair<double, double>> vertices2(numVertices);

    cout << "Ingrese las coordenadas de los vértices del primer polígono (x y):\n";
    for (int i = 0; i < numVertices; ++i) {
        cin >> vertices1[i].first >> vertices1[i].second;
    }

    cout << "Ingrese las coordenadas de los vértices del segundo polígono (x y):\n";
    for (int i = 0; i < numVertices; ++i) {
        cin >> vertices2[i].first >> vertices2[i].second;
    }

    VertexPolygon polygon1(vertices1);
    VertexPolygon polygon2(vertices2);

    if (polygon1.isSimilarTo(polygon2)) {
        cout << "Los polígonos son similares.\n";
    } else {
        cout << "Los polígonos no son similares.\n";
    }
    
}

// La función createPolygon permite al usuario seleccionar el tipo de polígono, 
// ingresar sus dimensiones y mostrar el área y el perímetro calculados.
void createPolygon() {
    int type;
    cout << "Seleccione el tipo de polígono:\n";
    cout << "1. Triángulo\n";
    cout << "2. Triángulo Isósceles\n";
    cout << "3. Triángulo Equilátero\n";
    cout << "4. Cuadrilátero\n";
    cout << "5. Rectángulo\n";
    cout << "6. Cuadrado\n";
    cout << "7. Pentágono\n";
    cout << "8. Hexágono\n";
    cout << "9. Octágono\n";
    cout << "10. Polígono por Vértices\n";
    cin >> type;

    Polygon* polygon = nullptr;

    if (type == 1) {
        double s1, s2, s3;
        cout << "Ingrese los lados del triángulo:\n";
        cin >> s1 >> s2 >> s3;
        polygon = new Triangle(s1, s2, s3);
    } else if (type == 2) {
        double equalSide, base;
        cout << "Ingrese los lados iguales y la base del triángulo isósceles:\n";
        cin >> equalSide >> base;
        polygon = new IsoscelesTriangle(equalSide, base);
    } else if (type == 3) {
        double side;
        cout << "Ingrese el lado del triángulo equilátero:\n";
        cin >> side;
        polygon = new EquilateralTriangle(side);
    } else if (type == 4) {
        double s1, s2, s3, s4;
        cout << "Ingrese los lados del cuadrilátero:\n";
        cin >> s1 >> s2 >> s3 >> s4;
        // polygon = new Quadrilateral(s1, s2, s3, s4); // Quadrilateral es abstracto, no se puede instanciar directamente
        cout << "Cuadrilátero genérico no implementado\n";
    } else if (type == 5) {
        double width, height;
        cout << "Ingrese el ancho y alto del rectángulo:\n";
        cin >> width >> height;
        polygon = new Rectangle(width, height);
    } else if (type == 6) {
        double side;
        cout << "Ingrese el lado del cuadrado:\n";
        cin >> side;
        polygon = new Square(side);
    } else if (type == 7) {
        double side;
        cout << "Ingrese el lado del pentágono:\n";
        cin >> side;
        polygon = new Pentagon(side);
    } else if (type == 8) {
        double side;
        cout << "Ingrese el lado del hexágono:\n";
        cin >> side;
        polygon = new Hexagon(side);
    } else if (type == 9) {
        double side;
        cout << "Ingrese el lado del octágono:\n";
        cin >> side;
        polygon = new Octagon(side);
    } else if (type == 10) {
        createVertexPolygon();
        return; // Salir temprano ya que createVertexPolygon maneja la creación y eliminación
    }

    if (polygon) {
        cout << "Área: " << polygon->area() << "\n";
        cout << "Perímetro: " << polygon->perimeter() << "\n";
        delete polygon;
    }
}

int main() {
    int option;
    while (true) {
        cout << "Seleccione una opción:\n";
        cout << "1. Crear Polígono\n";
        cout << "2. Verificar Similitud\n";
        cout << "3. Salir\n";
        cin >> option;
        if (option == 1) {
            createPolygon();
        } else if (option == 2) {
            checkSimilarity();
        } else {
            break;
        }
    }
    return 0;
}
