/****************************************
@Author: Joseph Cox U00594912


@Def: Project Imp file
*******************************************/
# include "mover.h"
using namespace std;

Mover::Mover (fstream& infile);

//Getters/Setters for maxCount
Mover::int getMaxCount() const;

Mover::void setMaxCount();

//Getters/Setters for currentCount
Mover::int getCurrentCount() const;

Mover::void setCurrentCount();