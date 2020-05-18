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
	const int off_x = x;
	const int off_y = y;
	gfx.DrawRectDim(loc.x * dimension + off_x, loc.y * dimension + off_y,dimension,dimension,c);
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

void Board::DrawBoarder(){
	const int left = gfx.ScreenWidth / 2 - GridX / 2; // centered grid left board edge
	const int top = gfx.ScreenHeight / 2 - GridY / 2; // centered grid top board edge
	const int right = left + GridX; // centered grid right board edge
	const int bottom = top + GridY; // centered grid bottom board edge
	// Fill Title Color
	gfx.DrawRect(left, top, right, bottom, Colors::DarkGray);
	// Left Bar
	gfx.DrawRect(left - borderWidth - 2, top - borderWidth - 2, left - 2, bottom + 2, brdrColor);
	// Top Bar
	gfx.DrawRect(left - borderWidth - 2, top - borderWidth - 2, right + borderWidth + 2, top - 2, brdrColor);
	// Right Bar
	gfx.DrawRect(right + 2, top - 2, right + borderWidth + 2, bottom + 2, brdrColor);
	// Bottom with pad of 2
	gfx.DrawRect(left-borderWidth-2, bottom +2, right+borderWidth+2, bottom+borderWidth+2, brdrColor);
}

const int Board::GetBoardX(){
	return width * dimension;
}

const int Board::GetBoardY(){
	return height * dimension;
}