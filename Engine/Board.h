#pragma once
#include "Graphics.h"
#include "Location.h"

class Board{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& Loc, Color c);
	int GetGridHeight() const;
	int GetGridWidth() const;
	bool inBounds(const Location& loc) const;

private:
	static constexpr int dimension = 10; //20 pixels Square size for cells
	static constexpr int width = 96; //48 cells X
	static constexpr int height = 70; //35 cells Y
	Graphics& gfx;
};
