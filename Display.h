//
// Created by pault on 04/12/2024.
//

#ifndef DISPLAY_H
#define DISPLAY_H


#include "Grid.h"

class Display {
public:
    virtual ~Display() = default;

    virtual void renderGrid(const Grid& grid) = 0;
    virtual bool isGraphic() const = 0;
};

#endif //DISPLAY_H
