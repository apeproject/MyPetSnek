#include "Snake.h"
#include <assert.h>

#pragma region Snek Operatives
Snek::Snek(const Location& loc){ segments[ 0 ].InitHead(loc); }

void Snek::Move(const Location& delta_loc){
	for (int i = segmentSize - 1; i > 0; --i){
		segments[ i ].FollowTheLeader(segments[ i - 1 ]);
	}
	segments[ 0 ].Move(delta_loc);
}

void Snek::Grow(){ if (segmentSize < segmentsMax) ++segmentSize; }

void Snek::Draw(Board & brd) const{
	for (int i = 0; i < segmentSize; ++i){
		segments[ i ].Draw(brd);
	}
}

void Snek::SnekSegment::InitHead(const Location& hedloc){ //phuck naming same name not working
	loc = hedloc;
	c = HeadColor;
}
#pragma endregion

#pragma region SnekSegment Operatives
void Snek::SnekSegment::InitBody(){ c = BodyColor; }

void Snek::SnekSegment::FollowTheLeader(const SnekSegment& next){ loc = next.loc; }

void Snek::SnekSegment::Move(const Location& delta_loc){ 
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1); // only move 1 cube in x or y direction or break this shit diagnal move?
	loc.UpdateLoc(delta_loc); //loc(x,y) += (delta_loc(x,y);
} 

void Snek::SnekSegment::Draw(Board& brd) const{ brd.DrawCell(loc, c); }
#pragma endregion
