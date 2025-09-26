#pragma once
#include <string>
#include <sstream>
#include "Shape.h"

class ShapeFactory {
public:
    static Shape* CreateShape(const string& line);
};
