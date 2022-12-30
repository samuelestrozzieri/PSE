//Obstacle.cpp

#include "Obstacle.h"

#include <array>

/* Obstacle::~Obstacle()
{
} */

Obstacle::Obstacle(double x1, double y1, double x2, double y2)
         :x1_{x1}, y1_{y1}, x2_{x2}, y2_{y2}
{
    if (x1>x2){
        std::cerr << "Obstacle::Obstacle(double x1,...): x1 must be less than x2\n";
        exit(EXIT_FAILURE);
    }
    if (y1>y2){
        std::cerr << "Obstacle::Obstacle(double x1,...): y1 must be less than y2\n";
        exit(EXIT_FAILURE);
    }
    if ((remainder(abs(x1-x2),1.0) > .1e-17)||(remainder((y1-y2),1.0) > .1e-17)){
        std::cerr << "Obstacle::Obstacle(double x1,...): invalid obstacle position(s) inserted\n";
        exit(EXIT_FAILURE);
    }
}

std::array<double, 2> Obstacle::get_edgeMin() const
{
    return std::array<double, 2>({x1_,y1_});
}

std::array<double, 2> Obstacle::get_edgeMax() const
{
    return std::array<double, 2>({x2_,y2_});
}
