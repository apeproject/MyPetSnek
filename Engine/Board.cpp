#include "board.h"
#include <assert.h>


Board::Board(Graphics& gfx):gfx(gfx){}

void Board::DrawCell(const Location& loc, Color c){
	// screen bounds check
	assert(loc.x >= 0);
	assert(loc.x<width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	// draw the grid
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension,dimension,dimension,c);
}

int Board::GetGridHeight() const{
	return height;
}

int Board::GetGridWidth() const{
	return width;
}

bool Board::inBounds(const Location& loc) const{
	return loc.x >= 0 && loc.x < width && 
		loc.y >= 0 && loc.y < height;
}
