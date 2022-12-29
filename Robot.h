#ifndef Robot_h
#define Robot_h

#include <ostream>
#include <cmath>
//#include <cctype> //isdigit(a);

#include "Grid.h"

class Robot
{
public:
    //Constructor
    Robot(double radius, double x, double y);
    Robot(double radius, double x, double y, Grid grid);
    //~Robot();

    //Const member func.
    double get_dimentions() const;
    double get_xpos() const;
    double get_ypos() const;
    double get_robozone() const;

    //Non-const member func.
    // void set_dimentions(double dim);
    void set_xpos(double xpos);
    void set_ypos(double ypos);

private:
    double radius_; //Robot's dimension
    double x_; //X axes robot's position
    double y_; //Y axes robot's position
    double robozone_; //robot's zone of influence
};



#endif