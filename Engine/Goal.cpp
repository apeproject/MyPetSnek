#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snek& snek){
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snek& Snek){
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);
	//TODO: update later to not spawn in snake cells or other objects
	Location newLoc;
	do{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (Snek.IsInTile(newLoc));
	loc = newLoc;
}

void Goal::Draw(Board& brd) const{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const{
	return loc;
}
