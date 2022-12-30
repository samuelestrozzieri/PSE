//Obstacle.cpp

#include "Obstacle.h"

#include <array>

/* Obstacle::~Obstacle()
{
} */

Obstacle::Obstacle(double x1, double y1, double x2, double y2)
         :x1_{x1}, y1_{y1}, x2_{x2}, y2_{y2}
{
    if ((remainder(abs(x1-x2),1.0) > .1e-17)||(remainder((y1-y2),1.0) > .1e-17)){
        std::cerr << "Obstacle::Obstacle(double x1,...): invalid obstacle position(s) inserted\n";
        exit(EXIT_FAILURE);
    }
}

std::array<double, 2> Obstacle::get_edgeMin() const
{
    return std::array<double, 2>();
}
