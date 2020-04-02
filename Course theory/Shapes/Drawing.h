//
// Created by Teodora Dan on 2019-05-03.
//

#ifndef SHAPES_DRAWING_H
#define SHAPES_DRAWING_H

#endif //SHAPES_DRAWING_H

#pragma once
#include "Shape.h"
#include <vector>

class Drawing : public Shape
{
private:
    std::vector<Shape*> shapes;

public:
    Drawing(const std::string& name);
    ~Drawing();

    void draw() override;
    void add(Shape* s);
};

