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
	void DrawBoarder();
	const int GetBoardX();
	const int GetBoardY();

private:

	static constexpr int borderWidth = 4;
	static constexpr int borderPad = 2;
	static constexpr int dimension = 20; //pixels Square size for cell size
	static constexpr int width = 20; //cells X axis
	static constexpr int height = 20; //cells Y axis
	static constexpr int GridX = width * dimension;
	static constexpr int GridY = height * dimension;
	static constexpr int x = Graphics::ScreenWidth / 2 - width * dimension / 2; // center board X
	static constexpr int y = Graphics::ScreenHeight / 2 - height * dimension / 2; // center board Y
	static constexpr Color brdrColor = Colors::Blue;
	Graphics& gfx;
};
