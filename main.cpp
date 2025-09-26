#include <fstream>
#include "Factory.h"
#include "Shape.h"
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return 1;
    }

    std::vector<Shape*> shapes;
    std::string line;

    // Создаем фигуры из файла
    while (std::getline(file, line)) {
        Shape* shape = ShapeFactory::CreateShape(line);
        if (shape) {
            shapes.push_back(shape);
        }
    }

    // Выводим информацию о каждой фигуре
    for (Shape* shape : shapes) {
        shape->Draw();
        std::cout << "Периметр: " << shape->Perimeter() << "\n";
        std::cout << "Площадь: " << shape->Area() << "\n\n";
    }

    // Освобождаем память
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}