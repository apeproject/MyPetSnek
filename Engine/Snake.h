#pragma once
#include "Board.h"

class Snek{

private:
	class SnekSegment{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void FollowTheLeader(const SnekSegment& next);
		void Move(const Location& delta_loc);
		void Draw(Board& brd) const; // don't know why const at end than beginning
	private:
		Location loc;
		Color c;
	};
public:
	Snek(const Location& loc);
	void Move(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;

protected:
	static constexpr Color HeadColor = Colors::LightGray;
	static constexpr Color BodyColor = Colors::Gray;
	static constexpr int segmentsMax = 200;
	SnekSegment segments[ segmentsMax ];
	int segmentSize = 1; // cell/segments index first size is 0 (or 1 cell for lenght)
};