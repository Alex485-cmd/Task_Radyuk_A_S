#include "Factory.h"

Shape* ShapeFactory::CreateShape(const string& line) {
    stringstream ss(line);
    string type;
    ss >> type;

    if (type == "point") {
        double x, y;
        ss >> x >> y;
        return new Point(x, y);
    }
    else if (type == "rect") {
        double x1, y1, x2, y2;
        ss >> x1 >> y1 >> x2 >> y2;
        return new Rect(x1, y1, x2, y2);
    }
    else if (type == "line") {
        double x1, y1, x2, y2;
        ss >> x1 >> y1 >> x2 >> y2;
        return new Line(x1, y1, x2, y2);
    }
    else if (type == "square") {
        double x, y, l;
        ss >> x >> y >> l;
        return new Square(x, y, l);
    }
    else if (type == "rhomb") {
        double x, y, h, w;
        ss >> x >> y >> h >> w;
        return new Rhomb(x, y, h, w);
    }
    else if (type == "circle") {
        double x, y, r;
        ss >> x >> y >> r;
        return new Circle(x, y, r);
    }

    return nullptr;
}