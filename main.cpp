#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept> // Para manejo de excepciones
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
#include "Trapezoid.h"

using namespace std;

// Función para crear polígonos definidos por vértices
void createVertexPolygon() {
    int numVertices;
    cout << "Ingrese el número de vértices del polígono:\n";
    cin >> numVertices;

    vector<pair<double, double>> vertices(numVertices);
    cout << "Ingrese las coordenadas de los vértices (x y):\n";
    try {
        for (int i = 0; i < numVertices; ++i) {
            cin >> vertices[i].first;
            cin >> vertices[i].second;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return;
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
    try {
        for (int i = 0; i < numVertices; ++i) {
            cin >> vertices1[i].first;
            cin >> vertices1[i].second;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return;
    }

    cout << "Ingrese las coordenadas de los vértices del segundo polígono (x y):\n";
    try {
        for (int i = 0; i < numVertices; ++i) {
            cin >> vertices2[i].first;
            cin >> vertices2[i].second;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return;
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
        try {
            cin >> s1 >> s2 >> s3;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Triangle(s1, s2, s3);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 2) {
        double equalSide, base;
        cout << "Ingrese los lados iguales y la base del triángulo isósceles:\n";
        try {
            cin >> equalSide >> base;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new IsoscelesTriangle(equalSide, base);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 3) {
        double side;
        cout << "Ingrese el lado del triángulo equilátero:\n";
        try {
            cin >> side;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new EquilateralTriangle(side);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 4) {
        double s1, s2, s3, s4, height;
        cout << "Ingrese los lados del cuadrilátero y la altura:\n";
        try {
            cin >> s1 >> s2 >> s3 >> s4 >> height;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Trapezoid(s1, s2, s3, s4, height);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 5) {
        double width, height;
        cout << "Ingrese el ancho y alto del rectángulo:\n";
        try {
            cin >> width >> height;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Rectangle(width, height);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 6) {
        double side;
        cout << "Ingrese el lado del cuadrado:\n";
        try {
            cin >> side;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Square(side);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 7) {
        double side;
        cout << "Ingrese el lado del pentágono:\n";
        try {
            cin >> side;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Pentagon(side);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 8) {
        double side;
        cout << "Ingrese el lado del hexágono:\n";
        try {
            cin >> side;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Hexagon(side);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
    } else if (type == 9) {
        double side;
        cout << "Ingrese el lado del octágono:\n";
        try {
            cin >> side;
            if (cin.fail()) {
                throw invalid_argument("Se ingresó un valor no numérico.");
            }
            polygon = new Octagon(side);
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return;
        }
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
    try {
        int option;
        while (true) {
            cout << "Seleccione una opción:\n";
            cout << "1. Crear Polígono\n";
            cout << "2. Verificar Similitud\n";
            cout << "3. Salir\n";
            cin >> option;
            if (cin.fail()) {
                cin.clear(); // Restaura el estado de cin después de un fallo de lectura
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
                throw invalid_argument("Entrada no válida. Por favor, ingrese un número.");
            }
            if (option == 1) {
                createPolygon();
            } else if (option == 2) {
                checkSimilarity();
            } else if (option == 3) {
                break;
            } else {
                throw invalid_argument("Opción no válida. Por favor, seleccione 1, 2 o 3.");
            }
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
