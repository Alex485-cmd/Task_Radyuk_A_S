#pragma o#pragma once
#include <iostream>
using namespace std;
class Shape {
public:
    virtual void Draw() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
    virtual ~Shape() {}
};

class Point : public Shape {
private:
    double x, y;
public:
    Point(double x, double y) : x(x), y(y) {}

    void Draw() override {
        cout << "point at (" << x << ", " << y << ")\n";
    }

    double Perimeter() override { return 0; }
    double Area() override { return 0; }
};

class Rect : public Shape {
private:
    double x1, y1, x2, y2;
public:
    Rect(double x1, double y1, double x2, double y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {}

    void Draw() override {
        cout << "rect at (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")\n";
    }

    double Perimeter() override {
        double width = abs(x2 - x1);
        double height = abs(y2 - y1);
        return 2 * (width + height);
    }

    double Area() override {
        double width = abs(x2 - x1);
        double height = abs(y2 - y1);
        return width * height;
    }
};

class Rhomb : public Shape {
private:
    double x, y, h, w;
public:
    Rhomb(double x, double y, double h, double w)
        : x(x), y(y), h(h), w(w) {}

    void Draw() override {
        cout << "rhomb at (" << x << ", " << y << "), h = " << h << ", w = " << w << "\n";
    }

    double Perimeter() override {
        return 2 * sqrt(h * h + w * w);
    }

    double Area() override {
        return h * w;
    }
};

class Square : public Shape {
private:
    double x, y, l;

public:
    Square(double x, double y, double l)
        : x(x), y(y), l(l) {}
    void Draw() override {
        cout << "square at (" << x << ", " << y << "), length = " << l << "\n";
    }
    double Perimeter() override {
        return 4 * l;
    }
        double Area() override {
            return l * l;
        }
    };

    class Line : public Shape {
    private:
        double x1, y1, x2, y2;
    public:
        Line(double x1, double y1, double x2, double y2)
            : x1(x1), y1(y1), x2(x2), y2(y2) {}

        void Draw() override {
            cout << "line at (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")\n";
        }

        double Perimeter() override { return 0; }
        double Area() override { return 0; }
    };

    class Circle : public Shape {
    private:
        double x, y, r;
        const double PI = 3.1415;
    public:
        Circle(double x, double y, double r)
            : x(x), y(y), r(r) {}

        void Draw() override {
            cout << "circle at (" << x << ", " << y << "), radius = " << r << "\n";
        }

        double Perimeter() override {
            return 2 * PI * r;
        }

        double Area() override {
            return PI * r * r;
        }
    };