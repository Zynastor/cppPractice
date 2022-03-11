//
// Created by WorldPC on 2022-03-11.
//

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle {
private:
    Point upLeft;
    Point lowRight;
public:
    bool InitMembers(const Point &ul, const Point &lr);

    void ShowRecInfo() const;
};

#endif //UNTITLED_RECTANGLE_H