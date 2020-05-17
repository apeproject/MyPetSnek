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
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snek(const Location& loc);
	bool IsInTileNotEnd(const Location& cell_Loc) const;
	bool IsInTile(const Location& cell_Loc) const;
	void Move(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;

protected:
	static constexpr Color HeadColor = Colors::LightGray;
	static constexpr Color BodyColor = Colors::Gray;
	static constexpr int nSegmentsMax = 200;
	SnekSegment segments[ nSegmentsMax ];
	int nSegments = 1; // cell/segments index first size is 0 (or 1 cell for lenght)
};