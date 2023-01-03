#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <utility>
using std::pair;
#include <vector>
using std::vector;
#include <array>
using std::array;

#include "Grid.h"
#include "Robot.h"
#include "Obstacle.h"

//Buona per il potenziale attrattivo a = robot b = goal
//Compute Euclidean distance between two points inserting their coordinates x and y
double eudis(double Xa, double Ya, double Xb, double Yb)
{
   return hypot ((Xa-Xb), (Ya-Yb));
}
//Compute Euclidean distance between two points inserting them as array of double_type coordinates {x,y}
double eudis(std::array<double,2> pointA, std::array<double,2> pointB)
{
   return hypot ((pointA[0]-pointB[0]), (pointA[1]-pointB[1]));
}

std::pair<Obstacle,double> nearest_obs(double Xpos, double Ypos, vector<Obstacle> vecObs){
    double dist;
    array<double,2> Edgem;
    array<double,2> EdgeM;
    pair<Obstacle,double> p;
    for (vector<Obstacle>::const_iterator pos = vecObs.cbegin(); pos != vecObs.cend(); ++pos)
    {
        Edgem = (*pos).get_edgeMin();
        EdgeM = (*pos).get_edgeMax();
        if (Xpos <= EdgeM[0] && Xpos >= Edgem[0]) 
            dist = std::min(std::abs(Ypos - EdgeM[1]), std::abs(Ypos - Edgem[1]));
        else if (Ypos <= EdgeM[1] && Ypos >= Edgem[1])
            dist = std::min(std::abs(Xpos - EdgeM[0]), std::abs(Xpos - Edgem[0]));
        else if (Xpos < Edgem[0])
        {
            if (Ypos > EdgeM[1]) 
                dist = eudis(Xpos,Ypos,Edgem[0],EdgeM[1]);
            else if(Ypos < Edgem[1])
                dist = eudis(Xpos,Ypos,Edgem[0],Edgem[1]);
        }
        else if (Xpos > EdgeM[0])
        {
            if (Ypos > EdgeM[1]) 
                dist = eudis(Xpos,Ypos,EdgeM[0],EdgeM[1]);
            else if(Ypos < Edgem[1])
                dist = eudis(Xpos,Ypos,EdgeM[0],Edgem[1]);
        }
        else
        {
            std::cerr << "nearest_obs(): something gone wrong\n";
            exit(EXIT_FAILURE);
        }
        if (pos == vecObs.cbegin())
             p = std::make_pair(*pos,dist);
        if(dist < p.second)
        {
            p.first = *pos;
            p.second = dist;
        }
    }
}

std::pair<Obstacle,double> nearest_obs(array<double,2> Robot, vector<Obstacle> vecObs){
    double dist = -1.0;
    array<double,2> Edgem;
    array<double,2> EdgeM;
    pair<Obstacle,double> p;
    for (vector<Obstacle>::const_iterator pos = vecObs.cbegin(); pos != vecObs.cend(); ++pos)
    {
        Edgem = (*pos).get_edgeMin();
        EdgeM = (*pos).get_edgeMax();
        if (Robot[0] <= EdgeM[0] && Robot[0] >= Edgem[0]) 
            dist = std::min(std::abs(Robot[1] - EdgeM[1]), std::abs(Robot[1] - Edgem[1]));
        else if (Robot[1] <= EdgeM[1] && Robot[1] >= Edgem[1])
            dist = std::min(std::abs(Robot[0] - EdgeM[0]), std::abs(Robot[0] - Edgem[0]));
        else if (Robot[0] < Edgem[0])
        {
            if (Robot[1] > EdgeM[1]) 
                dist = eudis(Robot[0],Robot[1],Edgem[0],EdgeM[1]);
            if(Robot[1] < Edgem[1])
                dist = eudis(Robot,Edgem);
        }
        else if (Robot[0] > EdgeM[0])
        {
            if (Robot[1] > EdgeM[1]) 
                dist = eudis(Robot,EdgeM);
            else if(Robot[1] < Edgem[1])
                dist = eudis(Robot[0],Robot[1],EdgeM[0],Edgem[1]);
        }
        else
        {
            std::cerr << "nearest_obs(): something gone wrong\n";
            exit(EXIT_FAILURE);
        }
        if (pos == vecObs.cbegin())
             p = std::make_pair(*pos,dist);
        if((pos != vecObs.cbegin())&&(dist < p.second))
        {
            p.first = *pos;
            p.second = dist;
        }
    }
    return p;
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


    std::cout << eudis(robX,robY,obsX,obsY) << std::endl;
    std::cout << std::remainder(std::abs(2.5-3.),1.0) << std::endl;
    std::cout <<  std::remainder(a,b) << std::endl;
    std::cout << Robot1.get_robozone() << std::endl;
    std::cout << "grid cell dimentions are: " << grid1.get_grid() << "m" << std::endl;
    std::cout << "grid cell dimentions are: " << grid2.get_grid() << "m" << std::endl;
    std::cout << std::boolalpha << (grid1 == grid2) << std::endl;

    return 0;
}