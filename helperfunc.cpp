#include <iostream>
#include <iomanip>
#include <cmath>

#include "Grid.h"
#include "Robot.h"
#include "Obstacle.h"

double dist(double Xa, double Ya, double Xb, double Yb)
{
   return hypot ((Xa-Xb), (Ya-Yb));
}

int main(){

    double robX{2.2},robY{3.4},obsX{5.5},obsY{6.5};
    double a = 1.;
    double b = 0.02;
    //int c = 2;
    //double d = 100.0;
    //double e = c/d;
    Grid grid1{25,Grid::Unit::mm};
    Grid grid2{0.025};
    //grid1.get_grid();
    Robot Robot1{0.4, 0, 0, grid1};
    Obstacle Obs1{2.5,2.,3.5,4.};

    std::cout << dist(robX,robY,obsX,obsY) << std::endl;
    std::cout << std::remainder(std::abs(2.5-3.),1.0) << std::endl;
    std::cout <<  std::remainder(a,b) << std::endl;
    std::cout << Robot1.get_robozone() << std::endl;
    std::cout << "grid cell dimentions are: " << grid1.get_grid() << "m" << std::endl;
    std::cout << "grid cell dimentions are: " << grid2.get_grid() << "m" << std::endl;
    std::cout << std::boolalpha << (grid1 == grid2) << std::endl;

    return 0;
}