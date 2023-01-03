//Robot.cpp

#include "Robot.h"


Robot::Robot(double radius, double x, double y)
      :radius_{radius}, x_{x}, y_{y} {}

Robot::Robot(double radius, double x, double y, Grid grid)
      :radius_{radius}, x_{x}, y_{y}
{
    if (grid.get_grid() <= radius) robozone_ = ceil(radius/grid.get_grid());
    if (grid.get_grid() > radius) robozone_ = ceil(grid.get_grid()/radius);
}

double Robot::get_dimentions() const
{
    return radius_;
}

double Robot::get_xpos() const
{
    return x_;
}

double Robot::get_ypos() const
{
    return y_;
}

std::array<double,2> Robot::get_pos() const
{
    std::array<double,2> pos {x_,y_};
    return pos;
}

double Robot::get_robozone() const
{
    return robozone_;
}

std::array<double,2> Robot::whereis(int a)
{
    switch (a)
    {
    case 1:
        std::cout << "Robot is in position: (" << x_ <<" , " << y_ << ")\n";
        return get_pos();
        break;
    default:
        std::cout << "Robot is in position: (" << x_ <<" , " << y_ << ")\n";
        return {};
        break;
    }
}

/* void Robot::set_dimentions(double dim) 
{
    radius_ = dim;
} */

void Robot::set_xpos(double xpos)
{
    x_ = xpos;
}

void Robot::set_ypos(double ypos)
{
    y_ = ypos;
}

void Robot::set_pos(std::array<double,2> p)
{
    x_ = p[0];
    y_ = p[1];
}
// Robot::~Robot()
// {
// }