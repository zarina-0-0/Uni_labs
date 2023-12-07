#ifndef INC_3SEM_SQUARE_H
#define INC_3SEM_SQUARE_H
#include "shapes.h"

class Square: public Shapes{

private:

    double side_len;

public:

    Square():side_len(0){};
    Square(double side): side_len(side){};
    Square(const Square& other): side_len(other.side_len){};

    ~Square();
};
#endif //INC_3SEM_SQUARE_H
