//Grid.h

#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <ostream>
#include <array>
#include <string>
using std::string;
#include <cmath>

class Grid
{
public:
    enum class Unit {km, hm, dam, m, dm, cm, mm};
    Grid();
    Grid(double grid);
    Grid(int grid, Unit unit);

    //void set_grid(double g);

    double get_grid() const;
    
    
    //~Grid();
private:
    double grid_;
};

bool operator==(const Grid& grid1, const Grid& grid2);
bool operator!=(const Grid& grid1, const Grid& grid2);

std::ostream& operator<<(std::ostream& os, const Grid& g);
#endif