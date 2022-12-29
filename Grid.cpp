//Grid.cpp

#include "Grid.h"



const Grid& default_grid()
{
	static Grid gg{1.0}; // standard grid dimetion of 1 meter
	return gg;
}

Grid::Grid()
    :grid_{default_grid().get_grid()}
{
}

//Grid dimention's constructor
//_grid_'s unit must be meters
Grid::Grid(double grid)
    :grid_{grid}
{
    if (grid < 0.) {
        std::cerr << "Grid::Grid(double grid): grid not valid!\n";
        exit(EXIT_FAILURE);
        }
    if (grid < 1.){
        if(std::remainder(1.,grid) > .1e-17){
        std::cerr << "Grid::Grid(double grid): grid is not a meter's divisor\n";
        exit(EXIT_FAILURE);
        }
    }
    else if (std::remainder(grid,1.0) > .1e-17){
        std::cerr << "Grid::Grid(double grid): grid is not a meter's multiple\n";
        exit(EXIT_FAILURE);
    }
}

//Grid dimention's constructor specifing metric unit 
Grid::Grid(int grid, Unit unit)
{
    if (grid < 0.){
        std::cerr << "Grid::Grid(int grid, Unit unit): grid not valid!\n";
        exit(EXIT_FAILURE);
    }
    switch (unit)
    {
    case Unit::km:
        grid_ = (1000.0*grid);
        break;
    case Unit::hm:
        grid_ = (100.0*grid);
        break;
    case Unit::dam:
        grid_ = (10.0*grid);
        break;
    case Unit::m:
        grid_ = (1.0*grid);
        break;
    case Unit::dm:
        if(std::remainder(1.,(grid/10.0)) > .1e-17){
            std::cerr << "Grid::Grid(int grid, Unit unit): grid is not a meter's divisor\n";
            exit(EXIT_FAILURE);
        }
        grid_ = (grid/10.0);
        break;
    case Unit::cm:
        if(std::remainder(1.,(grid/100.0)) > .1e-17){
            std::cerr << "Grid::Grid(int grid, Unit unit): grid is not a meter's divisor\n";
            exit(EXIT_FAILURE);
        }
        grid_ = (grid/100.0);
        break;
    case Unit::mm:
        if(std::remainder(1.,(grid/1000.0)) > .1e-17){
            std::cerr << "Grid::Grid(int grid, Unit unit): grid is not a meter's divisor\n";
            exit(EXIT_FAILURE);
        }
        grid_ = (grid/1000.0);
        break;
    default:
        std::cerr << "Grid::Grid(int grid, Unit unit): unit not valid!\n";
        exit(EXIT_FAILURE);
        break;
    }
}


double Grid::get_grid() const
{
    return grid_;
}

// Grid::~Grid()
// {
// }

bool operator==(const Grid& grid1, const Grid& grid2)
{
    return (grid1.get_grid() == grid2.get_grid());
}
bool operator!=(const Grid& grid1, const Grid& grid2)
{
    return !(grid1.get_grid() == grid2.get_grid());
}

std::ostream& operator<<(std::ostream& os, const Grid& g)
{
	return os << g.get_grid() << "m";
}