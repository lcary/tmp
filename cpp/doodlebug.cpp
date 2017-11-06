// Walter Savitch, 2014 -- CH16# 9: Doodlebug program.

// The goal for this project is to create a simple two-dimensional
// predator-prey simulation. In this simulation the prey are ants
// and the predators are doodlebugs. These critters live in a world
// composed of a 20 × 20 grid of cells. Only one critter may occupy
// a cell at a time. The grid is enclosed, so a critter is not
// allowed to move off the edges of the world. Time is simulated in
// time steps. Each critter performs some action every time step.

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

const int POSSIBLE_ADJACENT_CELL_COUNT = 4;

const char ANT_CHAR = 'o';
const char DOODLEBUG_CHAR = 'X';
const char EMPTY_SPACE_CHAR = '-';

// ============================== Cell ==============================

class Cell
{
public:
    Cell();
    Cell(int xVal, int yVal);
    friend bool operator ==(const Cell& cell1, const Cell& cell2);
    int x;
    int y;
    std::string str() const;
};

typedef std::vector<Cell> CellVector;

Cell::Cell()
{ }

Cell::Cell(int xVal, int yVal) : x(xVal), y(yVal)
{ }

bool operator ==(const Cell& a, const Cell& b)
{
    return ((a.x == b.x) && (a.y == b.y));
}

std::string Cell::str() const
{
    return '(' + std::to_string(x) + ',' + std::to_string(y) + ')';
}


// ============================== Grid ==============================

CellVector getCell1dSet(int xMax, int yMax)
{
    CellVector cellSet;
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
            cellSet.push_back(Cell(x, y));
        }
    }
    return cellSet;
}

char** getCell2dArray(int xMax, int yMax)
{
    char** cellArray = 0;
    // create columns first
    cellArray = new char*[xMax];
    for (int x = 0; x < xMax; x++) {
        // create rows second
        cellArray[x] = new char[yMax];
        for (int y = 0; y < yMax; y++) {
            cellArray[x][y] = EMPTY_SPACE_CHAR;
        }
    }
    return cellArray;
}

class Grid
{
public:
    Grid(int x, int y);
    void display() const;
    Cell getRandomCellInGrid() const;
    void clearCell(const Cell& cell);
    void setCellValue(const Cell& cell, char value);
    char getCellValue(const Cell& cell) const;
    char getCellValue(int x, int y) const;
    CellVector getAdjacentCells(const Cell& cell) const;
    Cell getEmptyCell(const CellVector& adjacentCells, bool& found) const;
    Cell getRandomMatchingCell(const CellVector& cellSet, char matchChar, bool& found) const;
private:
    bool cellContains(const Cell& cell, char value) const	;
    bool isInRange(const Cell& cell) const;
    char** cell2dArray;
    const CellVector cell1dSet;
    const int xMax;
    const int yMax;
};

Grid::Grid(int x, int y) :
    xMax(x),
    yMax(y),
    cell1dSet(getCell1dSet(x, y)),
    cell2dArray(getCell2dArray(x, y))
{
    std::cout << "Grid created." << std::endl;
}

void Grid::clearCell(const Cell& cell)
{
    setCellValue(cell, EMPTY_SPACE_CHAR);
}

void Grid::setCellValue(const Cell& cell, char value)
{
    cell2dArray[cell.x][cell.y] = value;
}

Cell Grid::getRandomCellInGrid() const
{
    Cell cell;
    bool found = false;

    cell = getRandomMatchingCell(cell1dSet, EMPTY_SPACE_CHAR, found);

    if (found)
        return cell;
    else {
        // The user likely created too many organisms.
        std::cout << "ERROR: There are no remaining empty cells in grid.\n";
        std::cout << "INFO: Ensure # of organisms < # of cells in grid.\n";
        exit(1);
    }
}

char Grid::getCellValue(int x, int y) const
{
    return cell2dArray[x][y];
}

char Grid::getCellValue(const Cell& cell) const
{
    return getCellValue(cell.x, cell.y);
}

bool Grid::cellContains(const Cell& cell, char data) const
{
    return (getCellValue(cell) == data);
}

bool Grid::isInRange(const Cell& cell) const
{
    bool aboveMin = ((cell.x >= 0) && (cell.y >= 0));  // must be positive
    bool belowMax = ((cell.x < xMax) && (cell.y < yMax));
    return (aboveMin && belowMax);
}

CellVector Grid::getAdjacentCells(const Cell& cell) const
{
    CellVector actualAdjacentCells;

    int x = cell.x;
    int y = cell.y;

    Cell possibleAdjacentCells[POSSIBLE_ADJACENT_CELL_COUNT] = {
        Cell(x, y + 1),  // up
        Cell(x, y - 1),  // down
        Cell(x - 1, y),  // left
        Cell(x + 1, y)   // right
    };

    // if any location is off the grid, it's invalid.
    for (int i = 0; i < POSSIBLE_ADJACENT_CELL_COUNT; i++) {
        Cell possibleCell = possibleAdjacentCells[i];
        if (isInRange(possibleCell))
            actualAdjacentCells.push_back(possibleCell);
    }

    return actualAdjacentCells;
}

Cell Grid::getRandomMatchingCell(const CellVector& cellSet, char matchChar, bool& found) const
{
    Cell cell;
    int cellsSearched = 0;
    int numCells = cellSet.size();

    while (cellsSearched < numCells && !found) {
        int randIndex = (std::rand() % numCells);  // one of [0, 1, 2, 3]
        cell = cellSet[randIndex];
        if (cellContains(cell, matchChar)) {
            found = true;
        }
        cellsSearched++;
    }
    return cell;
}

Cell Grid::getEmptyCell(const CellVector& adjacentCells, bool& found) const
{
    return getRandomMatchingCell(adjacentCells, EMPTY_SPACE_CHAR, found);
}

void Grid::display() const
{
    for (int i = 0; i < xMax; i++) {
        for (int j = 0; j < yMax; j++) {
            std::cout << cell2dArray[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// ============================== Organism ==============================

class Organism
{
public:
    Organism(int requiredSurvivalTime, char organismSymbol, const Cell& cell);
    virtual ~Organism() = 0;
    virtual void move(const Cell& cell) = 0;
    Cell getCell() const;
    void setCell(const Cell& cell);
    int getTimeSurvived() const;
    void incrementTimeSurvived();
    bool readyToBreed() const;
    const char symbol;
protected:
    const int required_survival_time_for_breeding;
    int timeSurvived;
private:
    Cell myCell;
};

Organism::Organism(int requiredSurvivalTime, char organismSymbol, const Cell& cell) :
    myCell(cell),
    required_survival_time_for_breeding(requiredSurvivalTime),
    symbol(organismSymbol),
    timeSurvived(0)
{ }

Organism::~Organism() {}

bool Organism::readyToBreed() const
{
    if (getTimeSurvived() == 0)
        return false;
    return ((getTimeSurvived() % required_survival_time_for_breeding) == 0);
}

void Organism::setCell(const Cell& cell)
{
    this->myCell = cell;
}

Cell Organism::getCell() const
{
    return myCell;
}

int Organism::getTimeSurvived() const
{
    return timeSurvived;
}

void Organism::incrementTimeSurvived()
{
    timeSurvived++;
}

// ============================== Ant ==============================


class Ant : public Organism
{
public:
    Ant(const Cell& cell);
    ~Ant();
    void move(const Cell& cell);
};

Ant::~Ant() {}

Ant::Ant(const Cell& cell) : Organism::Organism(3, ANT_CHAR, cell)
{ }

void Ant::move(const Cell& cell)
{
    setCell(cell);
}

// ============================== Doodlebug ==============================

class Doodlebug : public Organism
{
public:
    Doodlebug(const Cell& cell);
    ~Doodlebug();
    void incrementLastAntMeal();
    bool isStarving() const;
    void move(const Cell& cell);
    void eatAnt();
private:
    int lastAntMeal;
    const int max_time_without_eating;
};

Doodlebug::~Doodlebug() {}

Doodlebug::Doodlebug(const Cell& cell) :
    Organism::Organism(8, DOODLEBUG_CHAR, cell),
    lastAntMeal(0),
    max_time_without_eating(3)
{ }

void Doodlebug::move(const Cell& cell)
{
    setCell(cell);
}


bool Doodlebug::isStarving() const
{
    return (lastAntMeal >= max_time_without_eating);
}

void Doodlebug::incrementLastAntMeal()
{
    lastAntMeal++;
}

void Doodlebug::eatAnt()
{
    lastAntMeal = 0;  // reset last ant meal, since doodlebug just ate
}

// ============================== Organism Creator ==============================

typedef std::vector<Doodlebug*> DoodlebugVector;
typedef std::vector<Organism*> OrganismVector;

// Instances of this creator contain instances of organisms
// Instances of this creator record instances of organisms

class OrganismCreator
{
public:
    OrganismCreator();
    virtual Organism* create(const Cell& cell) = 0;
    OrganismVector getOrganisms();
    void remove(const Cell& cell);
    int count() const;
protected:
    void store(Organism* organism);
    int findIndex(const Cell& cell);
    OrganismVector organisms;
};

OrganismCreator::OrganismCreator() { }

OrganismVector OrganismCreator::getOrganisms()
{
    return organisms;
}

void OrganismCreator::store(Organism* organismPtr)
{
    organisms.push_back(organismPtr);
}

int OrganismCreator::count() const
{
    return organisms.size();
}

int OrganismCreator::findIndex(const Cell& cell)
{
    for (int i = 0; i < organisms.size(); i++) {
        Cell orgCell = organisms[i]->getCell();
        if (orgCell == cell)
            return i;
    }

    std::cout << "Unable to find index of cell that should exist: " << cell.str() << std::endl;
    exit(1);
}

void OrganismCreator::remove(const Cell& cell)
{
    int index = findIndex(cell);
    Organism* ptr = organisms[index];
    organisms.erase(organisms.begin() + index);
    delete ptr;
    ptr = nullptr;
}

class AntCreator : public OrganismCreator
{
public:
    virtual Ant* create(const Cell& cell);
};

Ant* AntCreator::create(const Cell& cell)
{
    Ant* newAnt = new Ant(cell);
    store(newAnt);
    return newAnt;
}

class DoodlebugCreator : public OrganismCreator
{
public:
    virtual Doodlebug* create(const Cell& cell);
};

Doodlebug* DoodlebugCreator::create(const Cell& cell)
{
    Doodlebug* newDoodlebug = new Doodlebug(cell);
    store(newDoodlebug);
    return newDoodlebug;
}

// ============================== Grid Controller ==============================

// controls the grid, creating and removing organisms

class GridController
{
public:
    GridController();
    GridController(Grid* gridPtr);
    void createAnts(int count);
    void createDoodlebugs(int count);
    void display() const;
    void step();
private:
    Grid* grid;
    AntCreator* antCreator;
    DoodlebugCreator* doodlebugCreator;
    void moveAnts();
    void moveDoodlebugs();
    void removeOrganism(const Cell& cell, OrganismCreator* creator);
    void createOrganism(OrganismCreator* creator, const Cell& cell);
    void createOrganisms(OrganismCreator* creator, int count);
    void moveOrganism(Organism* organism, const Cell& newCell);
    CellVector getRandomizedAdjacentCells(const Cell& cell) const;
    Cell getNextAdjacentCell(Organism* organism, bool& found) const;
    Cell getNextDoodlebugCell(Doodlebug* doodlebug, bool& found);
    void breedIfPossible(Organism* organism, OrganismCreator* creator);
    Cell searchAnts(const CellVector& searchCells, bool& found) const;
    void moveOrganism(const Cell& cell);
};

GridController::GridController() { }

GridController::GridController(Grid* gridPtr) : grid(gridPtr)
{
    this->antCreator = new AntCreator();
    this->doodlebugCreator = new DoodlebugCreator();
}

void GridController::createOrganism(OrganismCreator* creator, const Cell& cell)
{
    Organism* organismPtr = creator->create(cell);
    grid->setCellValue(cell, organismPtr->symbol);
}

void GridController::createOrganisms(OrganismCreator* creator, int count)
{
    for (int i = 0; i < count; i++) {
        Cell cell = grid->getRandomCellInGrid();
        createOrganism(creator, cell);
    }
}

void GridController::createAnts(int count)
{
    createOrganisms(antCreator, count);
}

void GridController::createDoodlebugs(int count)
{
    createOrganisms(doodlebugCreator, count);
}

void GridController::removeOrganism(const Cell& cell, OrganismCreator* creator)
{
    creator->remove(cell);
    grid->clearCell(cell);
}

CellVector GridController::getRandomizedAdjacentCells(const Cell& cell) const
{
    CellVector adjacentCells = grid->getAdjacentCells(cell);
    std::random_shuffle(adjacentCells.begin(), adjacentCells.end());
    return adjacentCells;
}

Cell GridController::getNextDoodlebugCell(Doodlebug* doodlebug, bool& found)
{
    Cell cell = doodlebug->getCell();
    CellVector adjacentCells = getRandomizedAdjacentCells(cell);

    Cell nextCell = searchAnts(adjacentCells, found);

    if (found) {
        doodlebug->eatAnt();
        removeOrganism(nextCell, antCreator);
        return nextCell;
    } else {
        return grid->getEmptyCell(adjacentCells, found);
    }
}

Cell GridController::getNextAdjacentCell(Organism* organism, bool& found) const
{
    Cell cell = organism->getCell();
    CellVector adjacentCells = getRandomizedAdjacentCells(cell);
    return grid->getEmptyCell(adjacentCells, found);
}

Cell GridController::searchAnts(const CellVector& searchCells, bool& found) const
{
    return grid->getRandomMatchingCell(searchCells, ANT_CHAR, found);
}

void GridController::breedIfPossible(Organism* organism, OrganismCreator* creator)
{
    Cell breedCell;
    bool canBreed = false;

    CellVector adjacentCells = getRandomizedAdjacentCells(organism->getCell());

    breedCell = grid->getEmptyCell(adjacentCells, canBreed);

    if (canBreed) {
        createOrganism(creator, breedCell);
    }
}

void GridController::moveOrganism(Organism* organism, const Cell& newCell)
{
    grid->clearCell(organism->getCell());
    grid->setCellValue(newCell, organism->symbol);
    organism->move(newCell);
}

void GridController::moveDoodlebugs()
{
    Cell newCell;
    bool canMove;

    // During one turn, all the doodlebugs should move before the ants do.
    DoodlebugVector breedingDoodlebugs;
    DoodlebugVector starvingDoodlebugs;

    OrganismVector doodlebugs = doodlebugCreator->getOrganisms();

    for (int i = 0; i < doodlebugs.size(); i++) {
        canMove = false;
        Doodlebug* doodlebug = dynamic_cast<Doodlebug*>(doodlebugs[i]);

        newCell = getNextDoodlebugCell(doodlebug, canMove);

        if (canMove) {
            moveOrganism(doodlebug, newCell);
        }

        doodlebug->incrementLastAntMeal();
        doodlebug->incrementTimeSurvived();

        if (doodlebug->readyToBreed())
            breedingDoodlebugs.push_back(doodlebug);

        // If a doodlebug has not eaten an ant within the last three time steps,
        // then at the end of the third time step it will starve and die.
        // The doodlebug should then be removed from the grid of cells.
        if (doodlebug->isStarving())
            starvingDoodlebugs.push_back(doodlebug);
    }

    for (int i = 0; i < breedingDoodlebugs.size(); i++) {
        Doodlebug* doodlebug = breedingDoodlebugs[i];
        breedIfPossible(doodlebug, doodlebugCreator);
    }

    for (int i = 0; i < starvingDoodlebugs.size(); i++) {
        Doodlebug* doodlebug = starvingDoodlebugs[i];
        removeOrganism(doodlebug->getCell(), doodlebugCreator);
    }
}

void GridController::moveAnts()
{
    Cell newCell;
    bool canMove;
    OrganismVector ants = antCreator->getOrganisms();

    OrganismVector antsToBreed;
    for (int i = 0; i < ants.size(); i++) {
        canMove = false;
        Organism* ant = ants[i];

        newCell = getNextAdjacentCell(ant, canMove);

        if (canMove) {
            moveOrganism(ant, newCell);
        }

        ant->incrementTimeSurvived();

        if (ant->readyToBreed())
            antsToBreed.push_back(ant);
    }

    for (int i = 0; i < antsToBreed.size(); i++) {
        Organism* ant = ants[i];
        breedIfPossible(ant, antCreator);
    }
}

void GridController::step()
{
    moveDoodlebugs();
    moveAnts();
}

void GridController::display() const
{
    std::cout << "total # of doodlebugs: ";
    std::cout << doodlebugCreator->count() << std::endl;
    std::cout << "total # of ants: ";
    std::cout << antCreator->count() << std::endl;
    grid->display();
}

// ============================== Main ==============================

int main()
{
    std::string temp;
    int count = 0;

    std::srand(std::time(NULL));  // required for random function usage

    Grid* grid = new Grid(20, 20);
    GridController controller = GridController(grid);
    controller.display();

    // Initialize the world with 5 doodlebugs and 100 ants.
    controller.createAnts(100);
    controller.createDoodlebugs(5);
    std::cout << "Organisms created." << std::endl;
    controller.display();

    // After each time step, prompt the user to press
    // Enter to move to the next time step.

    while (true) {
        std::cout << "Press enter to move to the next time step.\n";
        std::getline(std::cin, temp);

        controller.step();
        count++;

        std::cout << "iterations: " << count <<std::endl;
        controller.display();
    }

    // You should see a cyclical pattern between the population of
    // predators and prey, although random perturbations may lead
    // to the elimination of one or both species.

    return 0;
}
