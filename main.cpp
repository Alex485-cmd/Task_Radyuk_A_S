#include <fstream>
#include "Factory.h"
#include "Shape.h"
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "������ �������� �����\n";
        return 1;
    }

    std::vector<Shape*> shapes;
    std::string line;

    // ������� ������ �� �����
    while (std::getline(file, line)) {
        Shape* shape = ShapeFactory::CreateShape(line);
        if (shape) {
            shapes.push_back(shape);
        }
    }

    // ������� ���������� � ������ ������
    for (Shape* shape : shapes) {
        shape->Draw();
        std::cout << "��������: " << shape->Perimeter() << "\n";
        std::cout << "�������: " << shape->Area() << "\n\n";
    }

    // ����������� ������
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}